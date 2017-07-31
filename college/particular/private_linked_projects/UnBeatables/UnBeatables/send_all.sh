cd behavior
./sendToNAO.sh $1
cd ../motion_integracao
./sendToNAO.sh $1
cd ../vision
./sendToNAO.sh $1
cd ../communication
./sendToNAO.sh $1
cd ..
scp data/etc/naoqi/autoload.ini nao@$1:/home/nao
ssh -o ControlMaster=auto -o ControlPath=/tmp/control_%l_%h_%p_%r -t -l nao $1 "sudo mv autoload.ini /etc/naoqi"
scp data/naoqi/preferences/autoload.ini nao@$1:/home/nao/naoqi/preferences
