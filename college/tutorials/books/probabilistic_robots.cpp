Parte 1: - basic mathematical framework that underlies all of the algorithms described in this book
	 - collection of filters for probabilistic state estimation
	 - specific probabilistic models that characterize mobile robot perception and motion
Parte 2: - describes a range of perceptual algorithms, which map sensor measurements into internal robot beliefs
	 - algorihtms for mobile robot localization 
	 - algorithms for map acquisition
	 - learning models
Parte 3: - introduces probabilistic planning and action selection algorihtms
Parte 4: - describes two robot systems that were controlled by probabilistic algorithms. These robots were deployed in museums as interactive 
           tourguide robots, where they managed to navigate reliably without the need to modify the museums in any way.

'livro:'
-> localização de markov (filtro de Bayes): 
  - ideia basica é a confiabilidade de ser uma porta dado que havia a probabilidade de já ter reconhecido uma porta: pag4
  - base para praticamente todos os algoritmos do livro
-------------------------------------------------------------------------------------------------------------------------------------------------
2 RECURSIVE STATE ESTIMATION
Section 2.4 Bayes filters, the recursive algorithm for state estimation
that forms the basis of virtually every technique presented in this book.

2.2 BASIC CONCEPTS IN PROBABILITY
-Tudo são variáveis randômicas
X denote a random variable
x denote a specific event that X might take on
X can take on the values head or tail
p(X = x)
p(x) instead of writing p(X = x).
Most techniques in this book address estimation and decision making in continuous spaces.
all continuous random variables possess probability density functions (PDFs).
Normal distribution = N(x;μ,σ^2 ), which specifies the random variable, its mean, and its variance = PDF.
p(x, y) = p(X = x and Y = y)
p(x, y) = p(x)*p(y) If X and Y are independent.
p(x | y) = p(X = x | Y = y) conditional probability.
p(x | y) = p(x, y)/p(y)
p(x | y) = p(x)*p(y)/p(y) = p(x) If X and Y are independent.
p(x) = sumy(p(x|y)*p(y))
Bayes rule => p(x|y) = p(y|x)*p(x)/p(y) = relates conditionals of the type p(x | y) to their “inverse,” p(y | x).
p(x) will be referred to as 'prior probability distribution', and y is called the data (e.g., a sensor measurement).
p(x | y) is called the 'posterior probability distribution over X'.
Bayes rule provides a convenient way to compute a posterior p(x | y) using the “inverse” conditional probability 
p(y | x) along with the prior probability p(x). In other words, if we are interested in inferring a quantity x from sensor data
y, Bayes rule allows us to do so through the inverse probability, which specifies the probability of data y assuming that x was the case.
The denominator of Bayes rule, p(y), does not depend on x. For this reason, p(y) −1 is often written as a normalizer variable, 
and generically denoted η:
p(x | y, z) = p(y | x, z)*p(x | z)/p(y | z)
p(x, y | z) = p(x | z) p(y | z) combining probabilities of independent random variables.
p(x | z) = p(x | z, y) Conditional independence.

2.3 ROBOT ENVIRONMENT INTERACTION
-The robot can also influence its environment through its actuators.
-Environments are characterized by state. State can be static (a wall), dynamic (a person) or hybrid.
-state variables: robot itself, such as its pose, velocity, whether or not its sensors are functioning correctly, and so on.
-states will be denoted x
-variables:
  -'pose' = 6 variables = xyz + '(pitch(rot.y), roll(rot.x), and yaw(rot.z))'-> kinematic state.
	  = location and orientation relative to an external coordinate system.
  -'actuators config' = joints of robotic manipulators = each degree of freedom is one more dimension -> kinematic state.
  -'velocity and joints velocity' = six velocity variables, one for each pose variables -> dynamic state.
  -'features in the environments' = visual appearance (color, texture).
  -'moving objects location and velocities' = Other moving entities possess their own kinematic and dynamic state.
  -'battery level, broken sensor'..
-complete xt = best future predictor, no good features are missing to predict the future.
-future is stochastic = depends on random variable.
-'Markov chains' = Temporal stochastic processes.
		 = modeling sequences of random events using states and transitions between states.
		 
2.3.2 Environment Interaction
  




