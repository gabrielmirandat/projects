/*
   Forma da rede
   nos - A,B e C
   [A] = [B] = [C] = 5

    A
    ||
    \/
    C
    ||
    \/
    B

    p(A) = uniforme

    p(C|A=k) = 3 se C <= k, resto eh 1

    p(B|C=k) = 3 se B == k, vizinho - 1 pro resto

    OBJ = P(ABC) = P(A).P(B|C).P(C|A)
*/


#include <dlib/bayes_utils.h>
#include <dlib/graph_utils.h>
#include <dlib/graph.h>
#include <dlib/directed_graph.h>
#include <iostream>

using namespace dlib;
using namespace std;

// Facilita leitura dos nodos
enum nodes
{
    A = 0,
    B = 1,
    C = 2
};

int main()
{
    try
    {
        // Use DEBUG ou ENABLE_ASSERTS na compilacao se usa esse namespace
        // para permitir checagem de erros
        using namespace bayes_node_utils;

        // Cria rede baysiana
        directed_graph<bayes_node>::kernel_1a_c bn;

        // Configura estrutura da rede
        bn.set_number_of_nodes(3);
        bn.add_edge(C, B);
        bn.add_edge(A, C);


        // Informa cardinalidade dos nos
        set_node_num_values(bn, A, 5);
        set_node_num_values(bn, B, 5);
        set_node_num_values(bn, C, 5);

        // Permite especificar estado dos pais
        assignment parent_state;

        // Probabilidades de A
        // p(A=a) = 0.2 uniforme
        set_node_probability(bn, A, 0, parent_state, 0.2);
        set_node_probability(bn, A, 1, parent_state, 0.2);
        set_node_probability(bn, A, 2, parent_state, 0.2);
        set_node_probability(bn, A, 3, parent_state, 0.2);
        set_node_probability(bn, A, 4, parent_state, 0.2);
        // xxx

        // Probabilidades de C dado A
        // p(C|A=k) = 3 se C <= k, resto eh 1
        double ratioC[5] = {7.0, 9.0, 11.0, 13.0, 15.0};
        for(int a=0; a<5; a++)
        {
            if(a==0) parent_state.add(A,a);
            else parent_state[A] = a;

            for(int c=0; c<5; c++)
            {
                if(c <= a) set_node_probability(bn, C, c, parent_state, 3.0/ratioC[a]);
                else set_node_probability(bn, C, c, parent_state, 1.0/ratioC[a]);
            }
        }
        // xxx

        parent_state.clear();
        // Probabilidades de B dado C
        // p(B|C=k) = 3 se B == k, vizinho - 1 pro resto
        double ratioB[5] = {15.0, 18.0, 19.0, 18.0, 15.0};
        for(int c=0; c<5; c++)
        {
            if(c==0) parent_state.add(C,c);
            else parent_state[C] = c;

            for(int b=0; b<5; b++)
            {
                int dif = abs(b-c);

                if(dif == 0) set_node_probability(bn, B, b, parent_state, 5.0/ratioB[c]);
                else if(dif == 1) set_node_probability(bn, B, b, parent_state, 4.0/ratioB[c]);
                else if(dif == 2) set_node_probability(bn, B, b, parent_state, 3.0/ratioB[c]);
                else if(dif == 3) set_node_probability(bn, B, b, parent_state, 2.0/ratioB[c]);
                else if(dif == 4) set_node_probability(bn, B, b, parent_state, 1.0/ratioB[c]);
            }
        }
        // xxx

        // Join Tree para realizar inferencia
        typedef dlib::set<unsigned long>::compare_1b_c set_type;
        typedef graph<set_type, set_type>::kernel_1a_c join_tree_type;
        join_tree_type join_tree;

        // Associa a rede a join_tree
        create_moral_graph(bn, join_tree);
        create_join_tree(join_tree, join_tree);

        // Obtem solucionador de inferencia
        bayesian_network_join_tree solution(bn, join_tree);

        double pA1 = solution.probability(A)(1);
        cout << "p(A=1) = " << solution.probability(A)(1) << endl;
        cout << "p(B=2) = " << solution.probability(B)(2) << endl;
        cout << "p(C=3) = " << solution.probability(C)(3) << endl;
        cout << "\n";

        // Ao observar que C eh 4
        set_node_value(bn, C, 4);
        set_node_as_evidence(bn, C);
        bayesian_network_join_tree solution_seen_c(bn, join_tree);

        // Mostra algumas probabilidades
        double pB3C4 = solution_seen_c.probability(B)(3);
        cout << "p(A=1 | C=4) = " << solution_seen_c.probability(A)(1) << endl;
        cout << "p(B=3 | C=4) = " << solution_seen_c.probability(B)(3) << endl;
        cout << "\n";

        set_node_as_nonevidence(bn, C);
        // Ao observar que A eh 1
        set_node_value(bn, A, 1);
        set_node_as_evidence(bn, A);
        bayesian_network_join_tree solution_seen_a(bn, join_tree);

        // Mostra algumas probabilidades
        double pC4A1 = solution_seen_a.probability(C)(4);
        cout << "p(C=4 | A=1) = " << solution_seen_a.probability(C)(4) << endl;
        cout << "\n";

        // P(ABC) = P(A).P(B|C).P(C|A)
        cout << "p(A=1,B=3,C=4) = " << pA1 * pB3C4 * pC4A1 << endl;
        cout << "\n";

    }
    catch (std::exception& e)
    {
        cout << "exception thrown: " << endl;
        cout << e.what() << endl;
        cout << "hit enter to terminate" << endl;
        cin.get();
    }
}



