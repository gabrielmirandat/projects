Gitlab:
    New project
    Adiciona webhook para disparar jenkins

  Git local:
    Cria dir do projeto e entra nele
    git init

  Gradle:
    OU: gradle init --type groovy-library (ou java-library)
    OU 
      spring-boot: 
        Entra em https://start.spring.io/
        Escolhe gradle project
        Escolhe linguagem: groovy/java/kotlin
        Escolhe versão do spring boot (última release)
        Coloca group, artifact, e dependências*
        Clica em Generate Project
        Faz unzip do download no diretório do git

  Git local:
    git remote add origin <url-do-REPOSITORIO-git-criado-em-new-project>
    git add .
    git commit -m "Primeiro commit"
    git push -u origin master

  Jenkins:
    Cria Jenkinsfile** no projeto para o pipeline e faz commit/push
    Cria job pipeline no jenkins e aponta o projeto e onde fica o Jenkinsfile dele​