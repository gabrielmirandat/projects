/* animals.pl 
 *  
 * Animal guessing game. Save this file as animals.pl, start the SWIPL Prolog
 * interpreter, invoke swipl, and load the file as at the swipl 
 * prompt as [animals].
 *
 * Author: R. Canosa
 * Date: 10/23/2013
 *
 * start with ?- go.     
*/

go :- nl,
      write('Think of an animal and I will attempt to guess what it is.'),
      nl,
      write('Please answer yes or no to the following questions:'),
      nl, nl,
      guess(Animal),
      write('The animal is a '),
      write(Animal),
      nl,
      undo.

/* hypotheses to be tested */
guess(zebra)        :- zebra, !.
guess(horse)        :- horse, !.
guess(giraffe)      :- giraffe, !.
guess(sheep)        :- sheep, !.
guess(koala)        :- koala, !.
guess(kangaroo)     :- kangaroo, !.
guess(rabbit)       :- rabbit, !.
guess(hare)         :- hare, !.
guess(squirrel)     :- squirrel, !.
guess(gorilla)      :- gorilla, !.
guess(whale)        :- whale, !.
guess(dolphin)      :- dolphin, !.
guess(porpoise)     :- porpoise, !.
guess(walrus)       :- walrus, !.
guess(seal)         :- seal, !.
guess(chimpanzee)   :- chimpanzee, !.
guess(mouse)        :- mouse, !.
guess(cat)          :- cat, !.
guess(dog)          :- dog, !.
guess(human)        :- human, !.
guess(hawk)         :- hawk, !.
guess(owl)          :- owl, !.
guess(dove)         :- dove, !.
guess(pigeon)       :- pigeon, !.
guess(penguin)      :- penguin, !.
guess(ostrich)      :- ostrich, !.
guess(chicken)      :- chicken, !.
guess(newt)         :- newt, !.
guess(salamander)   :- salamander, !.
guess(toad)         :- toad, !.
guess(frog)         :- frog, !.
guess(crocodile)    :- crocodile, !.
guess(alligator)    :- alligator, !.
guess(terrapin)     :- terrapin, !.
guess(tortoise)     :- tortoise, !.
guess(snake)        :- snake, !.
guess(lizard)       :- lizard, !.
guess(shark)        :- shark, !.
guess(eel)          :- eel, !.
guess(sunfish)      :- sunfish, !.
guess(unknown).             /* no diagnosis */

/* animal identification rules */
zebra :- warm_blooded, mammal, herbivore, ungulate, verify(have_black_stripes).
horse :- warm_blooded, mammal, herbivore, ungulate, verify(belong_in_a_rodeo).
giraffe :- warm_blooded, mammal, herbivore, ungulate, verify(have_long_neck).
sheep :- warm_blooded, mammal, herbivore, ungulate.
koala :- warm_blooded, mammal, herbivore, marsupial, verify(live_in_trees).
kangaroo :- warm_blooded, mammal, herbivore, marsupial.
rabbit :- warm_blooded, mammal, herbivore, lagomorphic, verify(call_itself_a__bunny).
hare :- warm_blooded, mammal, herbivore, lagomorphic.
squirrel :- warm_blooded, mammal, herbivore, verify(have_a_bushy_tail).
gorilla :- warm_blooded, mammal, herbivore.
whale :- warm_blooded, mammal, marine, dorsal, verify(have_a_large_body).
dolphin :- warm_blooded, mammal, marine, dorsal, verify(have_a_beak).
porpoise :- warm_blooded, mammal, marine, dorsal.
walrus :- warm_blooded, mammal, marine, verify(have_tusks).
seal :- warm_blooded, mammal, marine.
chimpanzee :- warm_blooded, mammal, tail, brown, verify(love_bananas).
mouse :- warm_blooded, mammal, tail, brown.
cat :- warm_blooded, mammal, tail, verify(meow).
dog :- warm_blooded, mammal, tail.
human :- warm_blooded, mammal.
hawk :- warm_blooded, flies, prey, verify(have_a_broad_wing_span).
owl :- warm_blooded, flies, prey.
dove :- warm_blooded, flies, verify(represent_peace).
pigeon :- warm_blooded, flies.
penguin :- warm_blooded, verify(live_in_Antarctica).
ostrich :- warm_blooded, verify(have_a_long_neck_and_long_legs).
chicken :- warm_blooded.
newt :- amphibian, tail, verify(have_rough_skin).
salamander :- amphibian, tail.
toad :- amphibian, verify(have_warty_dry_skin).
frog :- amphibian.
crocodile :- reptile, jaws, verify(have_V_shaped_snout).
alligator :- reptile, jaws.
terrapin :- reptile, shell, verify(need_water_to_wet_themselves).
tortoise :- reptile, shell.
snake :- reptile, verify(slither_on_the_ground).
lizard :- reptile.
shark :- fish, verify(star_in_the_movie_Jaws).
eel :- fish, verify(have_a_long_snakelike_body).
sunfish :- fish.

/* classification rules */
warm_blooded :- verify(have_warm_blood).
mammal    :- verify(female_give_milk).
herbivore :- verify(eat_only_plants_or_nuts).
amphibian :- verify(start_life__with_gills_and_later_develop_lungs).
reptile :- verify(have_scales_or_shell_covering_body).
fish :- verify(breath_through_gills).
tail :- verify(have_a_tail).
brown :- verify(usually_have_brown_fur).
marine :- verify(live_in_or_near_the_water).
dorsal :- verify(have_a_dorsal_fin).
prey :- verify(eat_small_animals).
ungulate  :- verify(have_hooves).
marsupial :- verify(have_a_pouch_for_babies).
lagomorphic :- verify(hop).
flies :- verify(fly).
jaws :- verify(have_powerful_jaws_to_tear_prey_apart).
shell :- verify(have_a_hard_shell_attached_to_skeleton).

/* how to ask questions */
ask(Question) :-
    write('Does the animal '),
    write(Question),
    write('? '),
    read(Response),
    nl,
    ( (Response == yes ; Response == y)
      ->
      assert(yes(Question)) ;
       assert(no(Question)), fail).

:- dynamic yes/1,no/1.

/* How to verify something */
verify(S) :-
   (yes(S) 
    ->
    true ;
    (no(S)
     ->
     fail ;
     ask(S))).

/* undo all yes/no assertions */
undo :- retract(yes(_)),fail. 
undo :- retract(no(_)),fail.
undo.

