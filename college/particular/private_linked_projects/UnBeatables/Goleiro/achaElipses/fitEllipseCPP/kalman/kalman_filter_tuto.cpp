#http://www.bzarg.com/p/how-a-kalman-filter-works-in-pictures/

- Where I demonstrate a Kalman filter figuring out the orientation of a free-floating body by 
looking at its velocity. Totally neat!
- You can use a Kalman filter in any place where you have uncertain information about some 
dynamic system, and you can make an educated guess about what the system is going to do next.

- ideal for systems which are continuously changing
- light on memory (they don’t need to keep any history other than the previous state)
- very fast, making them well suited for real time problems and embedded systems.

-> state Xk = (position, velocity) of the robot
-> position, velocity = state variables 
-> Estes parâmetros podem ser qualquer coisa que você quer trackear
 
- The Kalman filter assumes that both variables (postion and velocity, in our case) 
are random and Gaussian distributed
- Each variable has a mean value μ, which is the center of the random distribution 
(and its most likely state), and a variance σ2, which is the uncertainty:
- estimating a new position based on an old one: in here, both variables are correlated
- One measurement tells us something about what the others could be. And that’s the goal
of the Kalman filter, we want to squeeze as much information from our uncertain measurements
as we possibly can!
 
Covariance matrix ('Pk or Σ'): captura a correlação das variáveis. Cada elemento da matriz é o grau de 
correlação entre a i-ésima variável de estado e a j-ésima variável de estado.

- Duas informações no tempo k: melhor estimativa(média - Xk - das variáveis de estado) e sua matriz covariância('Pk').
- we need some way to look at the current state (at time k-1) and predict the next state at time k.
- Our prediction function works on all states (we dont know what is the real one) and returns us a new distribution.

Prediction matrix('Fk') = represents distribution transition between the old and the new one.
It takes every point in our original estimate and moves it to a new predicted location, which is where 
the system would move if that original estimate was the right one. But we still don’t know how to update
the covariance matrix.

Xk = Fk * Xk-1
Pk = Fk * Pk-1 * transposta(Fk)

'External influence'
If we know this additional information about what’s going on in the world, we could stuff it into a control vector
('uk→'), do something with it, and add it to our prediction as a correction. From here, we get a control matrix('Bx').

Xk = Fk * Xk-1 + Bk * uk→

'External uncertainty'
What about forces that we don’t know about?
Every state in our original estimate could have moved to a range of states.
Each point in Xk−1 is moved to somewhere inside a Gaussian blob with covariance Qk.
This produces a new Gaussian blob, with a different covariance (but the same mean).
New best estimate is a prediction made from previous best estimate, plus a correction 
for known external influences. 
New uncertainty is predicted from the old uncertainty, with some additional uncertainty
from the environment.

Pk = Fk * Pk-1 * transposta(Fk) + Qk

'Refining the estimate with measurements'

Sensor matrix('Hk') = represents the sensor values.
covariance of the sensor noise is ('Rk')
mean of the observed distribution is zk→
So now we have two Gaussian blobs: One surrounding the mean of our transformed prediction, and one surrounding 
the actual sensor reading we got.
If we have two probabilities and we want to know the chance that both are true, we just multiply them together.
 So, we take the two Gaussian blobs and multiply them:

uEXP→ = Hk * Xk 
ΣEXP = Hk * Pk * transposta(Hk)

The mean of this distribution is the configuration for which both estimates are most likely, and is therefore 
the best guess of the true configuration given all the information we have.

For nonlinear systems, we use the extended Kalman filter, which works by simply linearizing the
predictions and measurements about their mean.




