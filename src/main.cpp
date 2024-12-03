#include <bits/stdc++.h>

#include "filemgr.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    // load config
    filemgr::loadConfig("config.toml");

    // window parameters
    string windowName = filemgr::getStr({"window", "name"});
    int w = filemgr::getInt({"window", "w"}); int h = filemgr::getInt({"window", "h"});

    cout << windowName << endl;
    cout << w << "x" << h << endl;

    return 0;

}
