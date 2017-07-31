#include <iostream>
#include <memory>
#include <pthread.h>

class Foo
{
    public:
        void* func(void* arg)
        {
            std::cout << "Deu!" << std::endl;
        }
};

struct wrap {
    char * msg;
    Foo ins; 

    wrap( char* m, const Foo& f ) : msg(m), ins(f) {}
};

extern "C" void* call_func( void *f )
{
    std::auto_ptr< wrap > w( static_cast< wrap* >( f ) );
    w->ins.func(w->msg);

    return 0;
}

int main() {
    wrap* w = new wrap( "Hi dude", Foo() );
    pthread_t pt;

    pthread_create( &pt, NULL, call_func, w );
    pthread_join (pt, NULL);
}