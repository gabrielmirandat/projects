https://jenkins.io/doc/book/pipeline/

Jenkinsfile (Declarative Pipeline)
pipeline {
    agent any  -->1

    stages {
        stage('Build') {  -->2 
            steps {  -->3
                sh 'make'  -->4 
            }
        }
        stage('Test'){
            steps {
                sh 'make check'
                junit 'reports/**/*.xml'  -->5 
            }
        }
        stage('Deploy') {
            steps {
                sh 'make publish'
            }
        }
    }
}

agent indicates that Jenkins should allocate an executor and workspace for this part of the Pipeline.
stage describes a stage of this Pipeline.
steps describes the steps to be run in this stage
sh executes the given shell command
junit is a Pipeline step provided by the JUnit plugin for aggregating test reports.