QIBUILD
- cada ferramenta deve ser usada de uma worktree
- cada projeto deve estar dentro da worktree, e deve ter um qiproject.xml como root. É desta assim que os scripts acham pastas de trabalho.
- qibuild serve para fácil compilação. Ele manipula dependências entre projetos e suporta cross-compilation. 
- qibuild usa bibliotecas do sistema por default, mas com 'qitoolchain' podemos manipular sets de pacotes pré-compilados (chamados 'toolchains').
- Cross-compilation é apenas questão de usar um toolchain específico.
- passos para poder usar os scripts de qiBuild:
  1) criar uma worktree com 'qibuild init', e então registrar pastas de trabalho com 'qisrc add'.
      cd ~/work
      qibuild init
      mkdir my_first_proj
      # edit my_first_proj/qiproject.xml
      qisrc add my_first_proj
      
- qibuild é composto de duas partes: 
 -> o framework qibuild Cmake, que simplifica autoria de CMakeLists.txt.
 -> as linhas de comando qibuild/qitoolchain, que ajuda a construir projetos tomando dependências em conta e gerando pacotes pacotes binários.