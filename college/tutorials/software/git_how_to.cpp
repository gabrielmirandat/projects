# git pull
# git commit -m "Remove all the cats"
# git push


/*-----------------------------------------------------------------------------
staged:
Files are ready to be committed.

unstaged:
Files with changes that have not been prepared to be committed.

untracked:
Files aren't tracked by Git yet. This usually indicates a newly created file.

deleted:
File has been deleted and is waiting to be removed from Git.

add all:
You can also type git add -A . where the dot stands for the current directory, so everything in and beneath it is added. The -A ensures even 
file deletions are included.

git reset:
You can use git reset <filename> to remove a file or files from the staging area.

Staging Area:
A place where we can group files together before we "commit" them to Git.

Commit
A "commit" is a snapshot of our repository. This way if we ever need to look back at the changes we've made (or if someone else does), we will 
see a nice timeline of all changes.

Wildcards:
We need quotes so that Git will receive the wildcard before our shell can interfere with it. Without quotes our shell will only execute the 
wildcard search within the current directory. Git will receive the list of files the shell found instead of the wildcard and it will not be
able to add the files inside of the octofamily directory.

Check all the things!
When using wildcards you want to be extra careful when doing commits. Make sure to check what files and folders are staged by using git status
before you do the actual commit. This way you can be sure you're committing only the things you want.

More useful logs:
Use git log --summary to see more information for each commit. You can see where new files were added for the first time or where files were
deleted. It's a good overview of what's going on in the project.

git remote:
Git doesn't care what you name your remotes, but it's typical to name your main one origin.
It's also a good idea for your main repository to be on a remote server like GitHub in case your machine is lost at sea during a transatlantic 
boat cruise or crushed by three monkey statues during an earthquake.

Cool Stuff:
When you start to get the hang of git you can do some really cool things with hooks when you push.
For example, you can upload directly to a webserver whenever you push to your master remote instead of having to upload your site with an ftp 
client. Check out Customizing Git - Git Hooks for more information.

git stash:
Sometimes when you go to pull you may have changes you don't want to commit just yet. One option you have, other than commiting, is to stash 
the changes. Use the command 'git stash' to stash your changes, and 'git stash apply' to re-apply your changes after your pull.

HEAD
The HEAD is a pointer that holds your position within all your different commits. By default HEAD points to your most recent commit, so it can 
be used as a quick way to reference that commit without having to look up the SHA.

Commit Etiquette:
You want to try to keep related changes together in separate commits. Using 'git diff' gives you a good overview of changes you have made and 
lets you add files or directories one at a time and commit them separately.

The '--'
So you may be wondering, why do I have to use this '--' thing? git checkout seems to work fine without it. It's simply promising the command 
line that there are no more options after the '--'. This way if you happen to have a branch named octocat.txt, it will still revert the file, 
instead of switching to the branch of the same name.

Branching
Branches are what naturally happens when you want to work on multiple features at the same time. You wouldn't want to end up with a master 
branch which has Feature A half done and Feature B half done. Rather you'd separate the code base into two "snapshots" (branches) and work on 
and commit to them separately. As soon as one was ready, you might merge this branch back into the master branch and push it to the remote 
server.

All at Once
You can use:
git checkout -b new_branch
to checkout and create a branch at the same time. This is the same thing as doing:
git branch new_branch
git checkout new_branch

Remove all the things!
Removing one file is great and all, but what if you want to remove an entire folder? You can use the recursive option on git rm:
git rm -r folder_of_cats
This will recursively remove all folders and files from the given directory.

The '-a' option
If you happen to delete a file without using 'git rm' you'll find that you still have to 'git rm' the deleted files from the working tree. You 
can save this step by using the '-a' option on 'git commit', which auto removes deleted files with the commit.
git commit -am "Delete stuff"

Pull Requests
If you're hosting your repo on GitHub, you can do something called a pull request.
A pull request allows the boss of the project to look through your changes and make comments before deciding to merge in the change. It's a 
really great feature that is used all the time for remote workers and open-source projects.

Merge Conflicts
Merge Conflicts can occur when changes are made to a file at the same time. A lot of people get really scared when a conflict happens, but fear
not! They aren't that scary, you just need to decide which code to keep.
Merge conflicts are beyond the scope of this course, but if you're interested in reading more, take a look the section of the Pro Git book on 
how conflicts are presented.

Force delete
What if you have been working on a feature branch and you decide you really don't want this feature anymore? You might decide to delete the
branch since you're scrapping the idea. You'll notice that git branch -d bad_feature doesn't work. This is because -d won't let you delete 
something that hasn't been merged.
You can either add the --force (-f) option or use -D which combines -d -f together into one command.

Learning more about Git
We only scratched the surface of Git in this course. There is so much more you can do with it. Check out the Git documentation for a full list
of functions. The Pro Git book, by Scott Chacon, is an excellent resource to teach you the inner workings of Git.
help.github and GitHub Training are also great for anything related to Git in general and using Git with GitHub.


-----------------------------------------------------------------------------*/

>> git init 	//inicia um repositório na pasta que você está
Criar conta em Code School 'já criado'
>> git status //ver estado atual do projeto (se alguém mudou algo vai mostrar pra você, suponha que adicionaram new_arq.txt). Usar sempre.
	      //Git mostrará pra você se um arquivo já está no repositório ou na Staging Area ou não.
>> git add new_arq.txt	//para fazer Git rastrear mudanças que fizerem no arquivo new_arq.txt => manda pra Staging Area, mas não está
			//no repositório ainda. Podemos adicionar ou remover arquivos da stage antes de armazená-lo no repositório.
>> git commit -m "Adicionei ..."	//armazenar nossas mudanças no código com mensagem do que fizemos 
>> git add '*.txt'	//armazenar na Staging Area todos os arquivos novos adicionados de uma só vez
>> git commit -m 'Adicionei todos os arquivos de ..'
>> git log	//Nos mostra todos os commits que fizemos e na ordem em que fizemos
>> git remote add origin https://github.com/try-git/try_git.git //mandar repositório local para servidor GitHub na url
			       //https://github.com/try-git/try_git.git
>> git push -u origin master	//diz ao Git onde colocar os commits qdo estivermos prontos. O remoto se chama origin e o local default 
			        //master. O -u diz ao Git para se lembrar dos parâmetros, então poderemos usar apenas git push e ele saberá.
>> git pull origin master	//saber tudo o que foi feito no repositório remoto.
>> git diff HEAD		//mostra as diferenças do ultimo commit no server
>> git diff --staged		//para ver as mudanças que você acabou de staged.
>> git git reset octofamily/octodog.txt	//para retirar arquivo da Stage.
>> git checkout -- octocat.txt	//mesmo tirando do Stage, octodog ainda está lá. Com isto, se livra de todas as mudanças desde a ultima commited
				//de octocat.txt
>> git branch clean_up	//cria um novo branch chamada clean_up. Agora temos o master e o clean_up com tudo igual. Para consertar bugs em separado.
>> git checkout clean_up	//troca entre as branchs. Muda para o clean_up.
>> git rm '*.txt'	// tira da Stage e até remove do disco todos os txt do branch atual.
>> git commit -m "Remove all the cats"	//lembre-se de commit suas mudanças
>> git checkout master	//vai pro branch master
>> git merge clean_up	//une os branches novamente em um só, fazendo um merge das mudanças nos dois lados.
>> git branch -d clean_up	//deleta o branch clean_up, já que nos serve mais.
>> git push	//coloca tudo o que foi feito no repositório.