pipeline {
  agent {
    label 'docker-agent-c'
  }

  triggers {
    pollSCM('H/5 * * * *')
  }

  stages {
    stage('Build') {
      steps {
        echo 'Building..'
        sh '''
          ls -l
          gcc main.c -o main
        '''
      }
    }

    stage('Test') {
      steps {
        echo 'Testing..'
        sh '''
          ./main
        '''
      }
    }

    stage('Deliver') {
      steps {
        echo 'Delivering..'
        sh '''
          mkdir -p output/
          cp main output/
        '''
        archiveArtifacts artifacts: 'output/main', fingerprint: true
      }
    }
  }

  post {
    success {
      echo 'Pipeline completed successfully!'
    }
    failure {
      echo 'Pipeline failed!'
    }
    always {
      cleanWs()
    }
  }
}
