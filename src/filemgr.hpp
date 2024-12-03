#pragma once

#include <bits/stdc++.h>

#include "toml.hpp"

namespace filemgr {

    toml::table configTbl;

    void loadConfig(std::string configPath) {
        configTbl = toml::parse_file(configPath);
    }

    // getting elements

    std::string getStr(std::vector<std::string> elementLocation) {
        switch (elementLocation.size()) {
            case 1:
                return configTbl[elementLocation[0]].value<std::string>().value();
            case 2:
                return configTbl[elementLocation[0]][elementLocation[1]].value<std::string>().value();
        }
    }

    int getInt(std::vector<std::string> elementLocation) {
        switch (elementLocation.size()) {
            case 1:
                return configTbl[elementLocation[0]].value<int>().value();
            case 2:
                return configTbl[elementLocation[0]][elementLocation[1]].value<int>().value();
        }
    }

}