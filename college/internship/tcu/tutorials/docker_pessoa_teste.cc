Para o docker e o kubernetes

docker images
docker ps
docker stop <container_id>
docker rm $(docker ps -a -q)
docker rmi $(docker images -q) -f

kubectl delete deployment <deplyment_name>
kubectl delete pod <pod_name>


// CRIAR CONTAINER COM APLICACAO

Criar pasta /container_pessoa vazia com arquivo Dockerfile
Preencher Dockerfile de acordo com template em 
	http://stackoverflow.com/questions/40800172/running-angular2-application-in-docker

Cria imagem docker com 
	docker build --network=host -t pessoa:v1 .

Checa se imagem criada
	 docker images

Roda a aplicação
	docker run -d -p 4200:4200 pessoa:v1

// ESCALAR COM KUBERNETES
Inicia o cluster minikube usando virtual box
	minikube start
	minikube start --vm-driver="virtualbox" --insecure-registry="$REG_IP":80

Troca o contexto para minikube (ver contextos em ~/.kube/config)
	kubectl config use-context minikube

Verifica se kubectl está configurado para comunicar com seu cluster
	kubectl cluster-info

Seta o uso do Minikube Docker Daemon
	eval $(minikube docker-env)

Retira host minikube
	eval $(minikube docker-env -u)

Cria deployment que gerencia um Pod
	kubectl run pessoa --image=pessoa:v1 --port=4200

Ve deployments
	kubectl get deployments

Olha as Pod
	kubectl get pods
