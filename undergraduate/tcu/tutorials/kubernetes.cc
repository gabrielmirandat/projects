'Master' is coordinating the cluster
'Nodes' are where we run applications

Dado um cluster do kubernets, consigo rodar meus containers nele
A Pod is a group of one or more application containers (such as Docker or rkt) that includes shared storage (volumes), a unique cluster IP address and 
information about how to run them (like container image version or specific ports). Deployed in nodes with substitution in case of node failure. Atomic peace 
in Kubernets.
In case of a Node failure, new identical Pods will be deployed on other available Nodes.
Pods always run on Nodes.
A Node is a worker machine in Kubernetes and may be a VM or a physical machine, depending on the cluster.
On a Node you can have multiple pods.
The scheduling of Pods is performed automatically by the Master.
Kubelet, that acts as a bridge between the Kubernetes Master and the Nodes; it manages the Pods and the containers running on a machine.
A Kubernetes Service is an abstraction layer which defines a logical set of Pods and enables external traffic exposure, load balancing and service discovery for those Pods.
Scaling is accomplished by changing the number of replicas in a Deployment

$ kubectl get - list resources
$ kubectl describe - show detailed information about a resource
$ kubectl logs - print the logs from a container in a pod
$ kubectl exec - execute a command on a container in a pod

// start the cluster
$ minikube start

// cluster details
$ kubectl cluster-info

// view nodes in cluster
$ kubectl get nodes

// run app creating new deployment
// search for free node, 
// run is the command that will create a new deployment
$ kubectl run kubernetes-bootcamp --image=docker.io/jocatalin/kubernetes-bootcamp:v1 --port=8080

// list deployments
$ kubectl get deployments

// create route between terminal and Kubernetes cluster
$ kubectl proxy
$ export POD_NAME=$(kubectl get pods -o go-template --template '{{range .items}}{{.metadata.name}}{{"\n"}}{{end}}') echo Name of the Pod: $POD_NAME
$ curl http://localhost:8001/api/v1/proxy/namespaces/default/pods/$POD_NAME/

// look for existing Pods
$ kubectl get pods

// view what containers are inside that Pod and what images are used to build those containers
$ kubectl describe pods

// to access applications from our localhost, we need to create a proxy between our machine and the Kubernetes cluster
$ kubectl proxy

// get logs from the container
$ kubectl logs $POD_NAME

// execute commands directly on the container
// list the environment variables
$ kubectl exec $POD_NAME env

// start a bash session in Pod's container
$ kubectl exec -ti $POD_NAME bash

// source code of the app is in the server.js
$ cat server.js
$ curl localhost:8080

// to close container
$ exit

// look for existing pods
$ kubectl get pods

// list services
$ kubectl get services

// create new service and expose to external traffic
$ kubectl expose deployment/kubernetes-bootcamp --type="NodePort" --port 8080

// discover external port
$ kubectl describe services/kubernetes-bootcamp

// create environment variable which value is the Node port
$ export NODE_PORT=$(kubectl get services/kubernetes-bootcamp -o go-template='{{(index .spec.ports 0).nodePort}}')
echo NODE_PORT=$NODE_PORT
$ curl host01:$NODE_PORT

// to see name of labels
$ kubectl describe deployment

// use label to query list of pods
$ kubectl get pods -l run=kubernetes-bootcamp

// use label to list existing services
$ kubectl get services -l run=kubernetes-bootcamp

// store name of pod as POD_NAME
$ export POD_NAME=$(kubectl get pods -o go-template --template '{{range .items}}{{.metadata.name}}{{"\n"}}{{end}}')
echo Name of the Pod: $POD_NAME

// apply new label
$ kubectl label pod $POD_NAME app=v1

// describe lalelled pod
$ kubectl describe pods $POD_NAME

// delete service by label
$ kubectl delete service -l run=kubernetes-bootcamp

// scale to four pods
$ kubectl scale deployments/kubernetes-bootcamp --replicas=4

// scale down to two replicas
$ kubectl scale deployments/kubernetes-bootcamp --replicas=2

// view current image version of the app
$ kubectl describe pods

// update image version
$ kubectl set image deployments/kubernetes-bootcamp kubernetes-bootcamp=jocatalin/kubernetes-bootcamp:v2

// back to previous version
$ kubectl rollout undo deployments/kubernetes-bootcamp
