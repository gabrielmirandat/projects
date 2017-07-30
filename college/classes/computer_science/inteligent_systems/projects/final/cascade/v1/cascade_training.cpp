#Cascade Classifier Training



2 etapas: treinamento e detecção
2 aplicações para treinar: 'opencv_haartraining' and 'opencv_traincascade (nova-C++-Haar ou LBP)'
Haar - Viola(2001) 
LBP  - Liao (2007)
features 'LBP' são inteiras contra features 'Haar', logo tanto o treinamento quanto a detecção com 'LBP' é mais rápida.
qualidade da detecção depende: qualidade do dataset de treino e dos parâmetros de treino.	

Tanto 'opencv_haartraining' e 'opencv_traincascade' armazenam o classificador treinado em diferentes extensões de arquivos.
olhar classe CascadeClassifier

dataset = set de treino e set de teste.

utilidades auxiliares de treino:
  - 'opencv_createsamples' é usado para criar um dataset de treino de amostras positivas. A saída é um arquivo '*.vec', formato binário que contém 
  as imagens. Possui funcionalidades para gerar o dataset, escrevê-lo e vê-lo.
  
'Preparação dos dados de treino'
Para treinar precisamos de amostras. 
As amostras são 'negativas(imagens sem objeto)' ou 'positivas(imagens com objeto)'.
Set de negativos deve ser criado manualmente.
Set de positivos são criados usando a utilidade 'opencv_createsamples'.

'Amostras negativas ou background'
Enumeradas em arquivos especiais.
Arquivo texto onde cada linha é uma imagem.
Cada imagem deve ser maior que o tamanho da janela de treinamento.

//Directory structure:
    /img
      img1.jpg
      img2.jpg
    bg.txt
//File bg.txt:
    img/img1.jpg
    img/img2.jpg

'Amostras positivas'
Criadas pelo 'opencv_createsamples'.
Unica imagem com objeto ou coleção de imagens previamente marcadas.
Para algo simples e rígido, como a logo do opencv, você só precisa de uma imagem. Mas para faces, centenas ou milhares delas, com rostos de todos 
os tipos.
Dada a imagem da logo, um grande set de imagens positivas é criada do objeto através de rotações, mudanças na intensidade da logo assim como fundos 
arbitrários.
A quantidade e range desta randomização pode ser controlada por argumentos de linhas de comando da 'opencv_createsamples'.

//Alguns dos vários comandos
-vec <vec_file_name>
    Name of the output file containing the positive samples for training.
-img <image_file_name>
    Source object image (e.g., a company logo).

//Modos de operação do opencv_createsamples
-Criando set de treino de uma única ou coleção de imagens:
  - com um simples '.vec' de output.
  - com uma coleção de jpg e um arquivo com listas de anotações como saída.
  - com uma coleção de png e arquivos associados com listas de anotações como saída.
-Conversão da coleção de amostras marcadas em um formato .vec.
-Mostrar conteúdo do .vec.

'Criando set de treino de uma única imagem e uma coleção de fundos com um único .vec de saída'
- Imagem fonte é rotacionada randomicamente através dos 3 eixos. 
- Ângulo escolhido é limitado por '-max?angle'. 
- Pixels tendo intensidade de '[bg_color-bg_color_threshold;bg_color+bg_color_threshold]' são interpretados como transparentes. 
- Ruído branco é adicionado às intensidades do foreground. 
- Se '-inv' for especificado então pixels do foreground são invertidos. 
- Se '-randinv' for especificado então o algoritmo randomicamente seleciona se a inversão deve ser aplicada a esta amostra. 
- Finalmente, a imagem obtida é colocada em algum background arbitrário do arquivo de backgrounds, tem o tamanho alterado para o desejado 
especificado com '-w' e '-h' e armazenada no .vec, cujo nome é especificado por '-vec'.

'Criando set de treino como uma coleção de imagens PNG'
- '-img', '-bg', '-info' e 'pngoutput' devem ser especificados.
- '-info' deve incluir pelo menos um nível de hierarquia de diretórios.
- Este diretório será usado como o top-level para o set de treino.
//opencv_createsamples -img /home/user/logo.png -bg /home/user/bg.txt -info /home/user/annotations.lst -pngoutput -maxxangle 0.1 -maxyangle 0.1 -maxzangle 0.1

'Criando set de treino de uma coleção de imagens JPG'
- Similar ao anterior mas gera output em um formato diferente. Para este novo comportamento, '-img', '-bg' e '-info' devem ser especificados. 
//opencv_createsamples -img /home/user/logo.png -bg /home/user/bg.txt -info annotations.lst -maxxangle 0.1 -maxyangle 0.1 -maxzangle 0.1
//Directory structure:
    info.dat
    img1.jpg
    img2.jpg
//File info.dat:
    img1.jpg  1  140 100 45 45
    img2.jpg  2  100 200 50 50   50 30 25 25

'Convertendo a coleção marcada de amostras em um .vec'
- Amostras positivas devem ser obtidas de uma coleção previamente marcada. Esta coleção é descrita por um arquivo texto similar ao de descrição de 
backgrounds.
- Cada linha é uma imagem.
- linha = 		|filename|nº_objects|Rect(x,y,largura, altura)
- Para criar amostras positivas de uma coleção, '-info' deve ser especificado em vez de '-img'.
- Só é usado '-w', '-h', '-show' e '-num'.
- Objetos tem tamanho alterado para os targets e é armazenado no vec-file. Não há distorções.

//Directory structure:
    /img
      img1.jpg
      img2.jpg
    info.dat
//File info.dat:
    img/img1.jpg  1  140 100 45 45
    img/img2.jpg  2  100 200 50 50   50 30 25 25
    
'Ver .vec'
- '-vec', '-w', '-h'.



#Cascade training




- Alguns args:
//-data <cascade_dir_name>
Where the trained classifier should be stored.
//-vec <vec_file_name>
vec-file with positive samples (created by opencv_createsamples utility).
//Boosted classifer parameters:
//-bt <{DAB, RAB, LB, GAB(default)}>
Type of boosted classifiers: DAB - Discrete AdaBoost, RAB - Real AdaBoost, LB - LogitBoost, GAB - Gentle AdaBoost.

**Passar 'cascade.xml' gerado como parametro '-data'.

'Cascade Classification'
classifier = namely a cascade of boosted classifiers working with haar-like features
positive examples = scaled to the same size
negative samples = arbitrary images of the same size
saída do classificador é 1 se tem objeto e 0 se não tem
"cascade" - several simpler classifiers (stages) that are applied subsequently to a region of interest until at some stage the candidate is 
	    rejected or all the stages are passed
"boosted" - basic classifiers using one of four different boosting techniques (weighted voting). Currently Discrete Adaboost, Real Adaboost, 
	    Gentle Adaboost and Logitboost are supported.  
	    
	
//-------------------------------------------------NORMAL-------------------------------------------------//
#http://answers.opencv.org/question/28959/cascade-training-killed-and-bad_alloc/
- Try to set numPos = 0.9 * number_of_positive_samples and 0.99 as a minHitRate
- add -nonsym -mem 512 to your opencv_haartraining command

#http://stackoverflow.com/questions/16058080/how-to-train-cascade-properly
- it seems that there is a feature that perfectly separates positives from negatives, so you 
get HR=1 and FA=0. your problem is either extremely easy or not represented by your data
- number of positive samples should related be to negative around 2:1 (positive samples should be more)
- number of stages you should chose by yourselves (for me it is 12-13). the more stages you set 
the more precisely will be your cascade, but you can also overtrain your cascade and it wont find anything.
The precision of your cascade is shown by acceptanceRatio on the last stage it should be around this 
value 0.000412662 or less.
- But if you get acceptanceRatio like this 7.83885e-07 your cascade is probably overtrained and it wont find
anything, try to set less stages.
- !!! And one more important thing, when you train your cascade you should have more than one feature on your
stage beginning from 2 or 3 stage. If you have only one feature you wont get good cascade. You should work on
your training images (negative and positive samples).
- For training I have used:
//-data imgs/cascade/ -vec imgs/vector.vec -bg imgs/negat.dat -numPos 1900 -numNeg 900 -numStages 12  -featureType HAAR
//-minHitRate 0.999 -maxFalseAlarmRate 0.5 -w 24 -h 30 command
- If you have a small number of data, you need less number of stages to achieve the required false alarm rate you set up.
This means that the cascade classifier is "good enough" so it doesnt have to grow further. The total false positive ratio
is actually multiplied by every stages ratio, so after a point, the value is achieved. In your options you set it up to 0.9.
Consider making it higher, like 0.95 or more.
- You set maxFalseAlarmRate=0.9. This means that in each stage no more than 90% of the 40 negative samples (ie 36 samples) 
should lie inside the boundary of positives. When the algorithm manages to put outside that boundary at least 4 samples, it 
can go to the next stage. This worked for a few stages, until it happened (by mere chance) that less than 36 samples are already
inside the positive boundary since the beginning (remenber that negative samples extraction is a random process). So when the 
algorithm should operate the separation it has its job already done and it does not know how to procede.

#http://www.trevorsherrard.com/Haar_training.html
- 50~60 positive images and around 600~700 negative images works well
- keep an eye on the ratios, they need to be pretty close to each other.
- I have found the training to work much better when the negative images are highly varied.
// $ find ./positive_images -iname "*.jpg" > positives.txt 
// $ find ./negative_images -iname "*.jpg" > negatives.txt 
- Now find the ratio of the positive images sizes. reduce it by about a factor of 5~6 making
sure you keep the ratio equal. I have found that if the height and width added exceed about 150
then you will get a bad_alloc error when running the actual training program. "-w 80 -h 40" works well
for rectangular images with a width/height ratio of around 2.
- for square images (width height ratio of around 1), i have found that "-w 24 -h 24" works well. 
For this example using, my stop sign classifier, I will use -w 24 -h 24.
// $ perl bin/createsamples.pl positives.txt negatives.txt samples 1700 
// 	"opencv_createsamples -bgcolor 0 -bgthresh 0 -maxxangle 1.1
// 	-maxyangle 1.1 maxzangle 0.5 -maxidev 40 -w 24 -h 24"
- merge os vec gerados com mergevec
- In training, the -h and -w must be the same as the paramaters used in the sample creation. Also, 
-numPos must be less than the number of samples used in the sample creation.
// opencv_traincascade -data classifier -vec samples.vec -bg negatives.txt
//   -numStages 20 -minHitRate 0.999 -maxFalseAlarmRate 0.5 -numPos 1200
//   -numNeg 700 -w 24 -h 24 -mode ALL -precalcValBufSize 512
//   -precalcIdxBufSize 512
- The cloud. I have been able to train classifiers in ~20 minutes, with good results.

#http://www.computer-vision-software.com/blog/2009/06/opencv-haartraining-detect-objects-using-haar-like-features/
    Positive images, containing my object – about 3000 images, for training.
    Negative images – about 5000 images, for training.
    Positive images – about 100 for testing.
    Negative images – about 100 for testing.


//-------------------------------------------------BEST-------------------------------------------------//    
#http://www.computer-vision-software.com/blog/2009/11/faq-opencv-haartraining/	BEST
- Should lightning conditions and background be various on positive images? 
//Yes, it’s very important.
- There should be small background frame on positive image.
- You can use any image of OpenCV supported formats, which does not contain target objects
- Should negative images have the same size? 
//No. But the size should not be less than -w -h, which were put during vec file generation.
- How many negative/positive image should I take? 
//It depends on your task.  For real cascades there should be about 1000 positive images and
//2000 negative images e.g.
- best launch?? 
// haartraining -data haarcascade -vec samples.vec -bg negatives.dat -nstages 20  
// -minhitrate 0.999 -maxfalsealarm 0.5 -npos 1000 -nneg 2000 -w 20 -h 20 -nonsym -mem 1024
- What’ s falsealarm and hitrate of stage?
//You should read theory of adaboost about strong classifier. Stage is strong classifier.
//In short: 
- hitrate (HR)
//For example you have 1000 positive samples. You want your system to detect 900 of them. So 
//desired hitrate = 900/1000 = 0.9. Commonly, put minhitrate = 0.999.
- falsealarm (FA)
//For example you have 1000 negative samples. Because it’s negative, you don’t want your system
//to detect them. But your system, because it has error, will detect some of them. Let error be 
//about 490 samples, so false alarm = 490/1000 = 0.49. Commonly,put false alarm  = 0.5
- Are falsealarm and hitrate depend on each other?
//Yes, there is dependency. You could not put minhitrate = 1.0 and maxfalsealarm = 0.0.
- What’s falsealarm and hitrate of whole cascade?
//False alarm of cascade = false alarm of  stage 1* false alarm of  stage 2* …
//Hit rate = hitrate of  stage 1 * hitrate of stage 2* …
- How many stages should be used?
//If you set big number of stages, then you will achieve better false alarm, but it will take 
//more time for generating cascade.
//If you set big number of stages, then the detection time could be slower
//If you set big number of stages, then the worse hitrate will be (0.99*0.99*… etc). Commonly 14-25
//stages are enough
//It’s useless to set many stage, if you have small number of positive, negative samples
- What’s weighttrimming, eqw, bt, nonsym options?
//Really all these parameters are related to Adaboost, read theory. In short:
- nonsym
//If you positive samples are not X or Y symmetric, put -nonsym, -sym is default!
- eqw
//if you have different number of pos and neg images, it’s better to put no eqw.
- weighttrimming
//for calculation optimization. It can reduce calculation time a little, but quality may be worse.
- bt
//what Adaboost algorithm to use: Real AB, Gentle AB, etc.
- Average time to generate cascade on PC?
//-nstages 20 -minhitrate 0.999 -maxfalsealarm 0.5 -npos 4000 -nneg 5000 -w 20 -h 20 -nonsym -mem 1024.
//It took 6 days on Pentium 2.7GHZ 2GB RAM.

#http://note.sonots.com/SciSoftware/haartraining.html	BEST
Creating
Usage: ./createsamples
  [-info <description_file_name>]
  [-img <image_file_name>]
  [-vec <vec_file_name>]
  [-bg <background_file_name>]
  [-num <number_of_samples = 1000>]
  [-bgcolor <background_color = 0>]
  [-inv] [-randinv] [-bgthresh <background_color_threshold = 80>]
  [-maxidev <max_intensity_deviation = 40>]
  [-maxxangle <max_x_rotation_angle = 1.100000>]
  [-maxyangle <max_y_rotation_angle = 1.100000>]
  [-maxzangle <max_z_rotation_angle = 0.500000>]
  [-show [<scale = 4.000000>]]
  [-w <sample_width = 24>]
  [-h <sample_height = 24>]
  
"""1. Create training samples from one'"""
- create training samples from one image applying distortions.
- launched when options, -img, -bg, and -vec were specified.

    -img <one_positive_image>
    -bg <collection_file_of_negatives>
    -vec <name_of_the_output_file_containing_the_generated_samples>
    
//$ createsamples -img face.png -num 10 -bg negatives.dat -vec samples.vec -maxxangle 0.6 
//-maxyangle 0 -maxzangle 0.3 -maxidev 100 -bgcolor 0 -bgthresh 0 -w 20 -h 20    
- This generates <num> number of samples from one <positive_image> applying distortions.Be 
careful that only the first <num> negative images in the <collection_file_of_negatives> are used.
- Let me call this file format as 'collection file format'. To create it:
#$ find ../../data/negatives/ -name '*.jpg' > negatives.dat

"""2. Create training samples from some """
- create training samples from some images without applying distortions.
- launched when options, -info, and -vec were specified.

    -info <description_file_of_samples>
    -vec <name_of_the_output_file_containing_the_generated_samples>
    
//$ createsamples -info samples.dat -vec samples.vec -w 20 -h 20
- This generates samples without applying distortions. You may think this function as a file 
format conversion function.
- Let me call this format as a 'description file format' against the collection file format 
although. To create it after cropped images:
#$ find ../../data/umist_cropped -name '*.pgm' -exec identify -format '%i 1 0 0 %w %h' \{\} \; > samplesdescription.dat

"""3. Create test samples"""
- create test samples and their ground truth from single image applying distortions.
- triggered when options, -img, -bg, and -info were specified.

    -img <one_positive_image>
    -bg <collection_file_of_negatives>
    -info <generated_description_file_for_the_generated_test_images>
- In this case, -w and -h are used to determine the minimal size of positives to be embeded
in the test images.
//$ createsamples -img face.png -num 10 -bg negatives.dat -info test.dat -maxxangle 0.6 -maxyangle 0 
//-maxzangle 0.3 -maxidev 100 -bgcolor 0 -bgthresh 0
- Be careful that only the first <num> negative images in the <collection_file_of_negatives> 
are used.
- This generates tons of jpg files such as.

"""Create Training Samples"""
- We have to use the 1st function of the createsamples to generate 5 (or some) positives form 1 image, 
repeat the procedures 1000 (or some) times, and finally merge the generated output vec files.

Training:
Usage: ./haartraining
  -data <dir_name>
  -vec <vec_file_name>
  -bg <background_file_name>
  [-npos <number_of_positive_samples = 2000>]
  [-nneg <number_of_negative_samples = 2000>]
  [-nstages <number_of_stages = 14>]
  [-nsplits <number_of_splits = 1>]
  [-mem <memory_in_MB = 200>]
  [-sym (default)] [-nonsym]
  [-minhitrate <min_hit_rate = 0.995000>]
  [-maxfalsealarm <max_false_alarm_rate = 0.500000>]
  [-weighttrimming <weight_trimming = 0.950000>]
  [-eqw]
  [-mode <BASIC (default) | CORE | ALL>]
  [-w <sample_width = 24>]
  [-h <sample_height = 24>]
  [-bt <DAB | RAB | LB | GAB (default)>]
  [-err <misclass (default) | gini | entropy>]
  [-maxtreesplits <max_number_of_splits_in_tree_cascade = 0>]
  [-minpos <min_number_of_positive_samples_per_cluster = 500>]
  
//$ haartraining -data haarcascade -vec samples.vec -bg negatives.dat -nstages 20 -nsplits 2 -minhitrate 0.999
//-maxfalsealarm 0.5 -npos 7000 -nneg 3019 -w 20 -h 20 -nonsym -mem 512 -mode ALL
- The "-nonsym" option is used when the object class does not have vertical (left-right) symmetry. If object 
class has vertical symmetry such as frontal faces, "-sym (default)" should be used. It will speed up processing
because it will use only the half (the centered and either of the left-sided or the right-sided) haar-like features.
- The "-mode ALL" uses Extended Sets of Haar-like Features [2]. Default is BASIC and it uses only upright features,
while ALL uses the full set of upright and 45 degree rotated feature set.
- The "-mem 512" is the available memory in MB for precalculation [1]. Default is 200MB, so increase if more memory
is available. We should not specify all system RAM because this number is only for precalculation, not for all. The 
maximum possible number to be specified would be 2GB because there is a limit of 4GB on the 32bit CPU (2^32 ≒ 4GB), 
and it becomes 2GB on Windows (kernel reserves 1GB and windows does something more).  
- #Even if you increase the number of stages, the training may finish in an intermediate stage when it exceeded your 
desired minimum hit rate or false alarm because more cascading will decrease these rate for sure (0.99 until current 
* 0.99 next = 0.9801 until next). Or, the training may finish because all samples were rejected. In the case, you must
increase number of training samples.
- #You can use OpenMP (multi-processing) with compilers such as Intel C++ compiler and MS Visual Studio 2005 Professional
Edition or better. See How to enable OpenMP section.

"""Generate a XML File """
- If you want to convert an intermediate haartraining output dir tree data into a xml file, there is a software at the
OpenCV/samples/c/convert_cascade.c (that is, in your installation directory). Compile it.
//$ convert_cascade --size="20x20" haarcascade haarcascade.xml





















