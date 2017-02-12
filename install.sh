mkdir -f bin
mkdir -f lib
sudo apt-get -yq install libncurses5-dev libncursesw5-dev
cd lib
git clone git@github.com:google/googletest.git