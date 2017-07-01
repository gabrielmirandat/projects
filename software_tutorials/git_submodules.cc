# add submodule repo to general repo
# the submodule is standalone/independent
git submodule add <url_git_subm>

# when cloning the general repo, submodule dir is empty
# to fill submodule dir use
git submodule update --init
or
git submodule init
git submodule update

