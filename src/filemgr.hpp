#pragma once

#include <bits/stdc++.h>

#include "toml.hpp"

namespace filemgr {

    toml::table configTbl;

    void loadConfig(std::string configPath) {
        configTbl = toml::parse_file(configPath);
    }

    // 

    // getting elements

    std::string getStr(std::vector<std::string> elementLocation) {
        switch (elementLocation.size()) {
            case 1:
                return configTbl[elementLocation[0]].value<std::string>().value();
            case 2:
                return configTbl[elementLocation[0]][elementLocation[1]].value<std::string>().value();
        }
        return "ERROR";
    }

    int getInt(std::vector<std::string> elementLocation) {
        switch (elementLocation.size()) {
            case 1:
                return configTbl[elementLocation[0]].value<int>().value();
            case 2:
                return configTbl[elementLocation[0]][elementLocation[1]].value<int>().value();
        }
        return -1;
    }

    std::vector<std::string> getStrVec(std::vector<std::string> elementLocation) {
        std::vector<std::string> tmpVec;
        toml::array* tmpArr;
        switch (elementLocation.size()) {
            case 1:
                tmpArr = configTbl[elementLocation[0]].as_array();
            case 2:
                tmpArr = configTbl[elementLocation[0]][elementLocation[1]].as_array();
        }
        for (auto &i : *tmpArr) {
            tmpVec.push_back(*i.value<std::string>());
        }
        return tmpVec;
    }

}