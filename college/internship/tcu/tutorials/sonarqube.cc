https://docs.sonarqube.org/display/SCAN/Analyzing+with+SonarQube+Scanner

SonarQube Scanner is recommended as the default launcher to analyze a project with SonarQube

https://docs.sonarqube.org/display/SONAR/Get+Started+in+Two+Minutes

2. Start the SonarQube server:
'$ /etc/sonarqube/bin/[OS]/sonar.sh console'


3. Configure and start Sonar Scanner
// sonar-project.properties
# must be unique in a given SonarQube instance
sonar.projectKey=my:project
# this is the name and version displayed in the SonarQube UI. Was mandatory prior to SonarQube 6.1.
sonar.projectName=My project
sonar.projectVersion=1.0
 
# Path is relative to the sonar-project.properties file.
# This property is optional if sonar.modules is set. 
sonar.sources=.
 
# Encoding of the source code. Default is default system encoding
#sonar.sourceEncoding=UTF-8

'$ sonar-scanner'

Jenkins in raw configuration 
            steps {
                sh '/etc/sonarqube-5.6.6/bin/linux-x86-64/sonar.sh console'
            }
            steps {
                sh '/etc/sonar-scanner-3.0.3.778-linux/bin/sonar-scanner'
            }

Jenkins as plugin
            steps {
                sh './gradlew sonarqube'
            }           