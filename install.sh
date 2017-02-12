mkdir bin
mkdir lib
sudo apt-get -yq install libncurses5-dev libncursesw5-dev
sudo apt-get -yq install libboost-all-dev
cd lib; git clone git@github.com:google/googletest.git; cd ..
