//
// Created by fang on 2022/7/28.
//

#pragma once

#include "nlohmann/json.hpp"

using namespace std;

namespace bilibili {

    class HistoryVideoListCursor {
    public:
        int max = 0;
        int view_at = 0;
        std::string business = "";
        int ps = 20;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(HistoryVideoListCursor, max, view_at, business, ps);

    class HistoryVideoData {
    public:
        int oid;
        int epid;
        int cid;
        std::string bvid;
        std::string business;
        int dt; // device type: 4: 平板  1： 手机  2：电脑
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(HistoryVideoData, oid, epid, cid, business, dt, bvid);

    class HistoryVideoResult {
    public:
        std::string title;
        std::string show_title;
        std::string author_name;
        std::string cover;
        std::string badge;
        HistoryVideoData history;
        int view_at;
        int duration;
        int progress; // -1：表示看完了
    };
    inline void from_json(const nlohmann::json& nlohmann_json_j, HistoryVideoResult& nlohmann_json_t) {
        NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM, title, show_title, author_name, cover,
                                                 badge, progress, duration, view_at, history));
    }


    typedef std::vector<HistoryVideoResult> HistoryVideoListResult;


    class HistoryVideoResultWrapper {
    public:
        HistoryVideoListCursor cursor;
        HistoryVideoListResult list;
    };
    inline void from_json(const nlohmann::json& nlohmann_json_j, HistoryVideoResultWrapper& nlohmann_json_t) {
        NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM, cursor, list));
    }

};