--Codigo do goleiro--

enum
{
    goal=0,
    center=1,
    post=2,
    ball=3,
    base=4,
}

tem duas imagens
imTop = goal, center, post, ball
imDown = ball, base



vector<base> entities= {new goal, new center, new post, new ball, new base}

for it=0 to 3
    entities[i].detect(imTop);
for it=3 to 4
    entities[i].detect(imDown);

goalskeeper.setGoalPos = entities[goal].getPos;
.
.
goalskeeper.setBasePos = entities[goal].getPos;
