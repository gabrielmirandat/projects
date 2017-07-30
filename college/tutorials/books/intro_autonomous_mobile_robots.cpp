1)    Motion Control / Locomotion
2)    Perception
3)    Localization
4)    Cognition / Path Planning

"Introduction to Autonomous Mobile Robots", Siegwart, Nourbakhsh, Scaramuzza, The MIT Press, 2011

esquemas de localização: Markov localization and kalman filter localization
			 Simultaneous Localization and 	Mapping (SLAM)
			    - Extended Kalman filter SLAM
			    - graph-based SLAM
			    - particle filter SLAM
			    - monocular visual SLAM
planing and navigation: robot control

livro: cap 2

'sFly - Vision only autonomous navigation'

'cognição': processo ou faculdade de adquirir um conhecimento.
'path planning': planejamento de trajetória.

'ciclo ver-pensar-agir'
agir = controle de movimento
ver = percepção
pensar = planejar trajeto


'Locomotion and Kinematics 1 (Legs)'

livro - 16 - 2.1.1

-mapeamento poincaré - um dos autores da relatividade.
-Monodromy matrix
-'Atuador' é um elemento que produz movimento, atendendo a comandos que podem ser manuais,
  elétricos ou mecânicos.
-The best way to illustrate this is by plotting
the state space of the main body-- so its vertical velocity,
horizontal velocity, and its height.
Now, to analyze the highly nonlinear dynamics,
we can focus on a single fixed point-- in this case,
the apex, which is the highest point in flight curve--
and project the dynamics onto the corresponding transversal plane--
the so-called Poincare section.
-Ponto é estável se vc pertuba e ele volta pra mesma altura e velocidade no mapa de poincaré.
- generalized coordinates and jacobians
-However, in most cases, the generalized coordinates
are chosen such that they directly correspond to the joint or actuator
degrees of freedom.
So, for example, a rotational joint-- as here in the middle--
naturally gets a relative angle as corresponding generalized coordinate.
From now on, we'll describe all kinematic properties
as a function of q.
The second important construct that you permanently need in kinematics
are Jacobians which correspond to the partial derivative of vectors
with respect to generalized coordinates.
Jacobians are used to map changes, so deltas or velocities--
which are changes per time-- from generalize
coordinates to Cartesian space or to any other space
the vector was represented in.
-inverse differential kinematics approach.
-Moore-Penrose.

'Locomotion and Kinematics II (Wheels)'

- holonomic and non-holonomic robots = kinematic constraints of the robot chassis.
-holonomic = robot is able to move instantaneously in any direction in its workspace.
-non-holonomic = not possible. Not possible to take the differential constraints and re-express them as a constraint pose.
-pose of an object = position + orientation.