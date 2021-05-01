//
// Created by Azad_zhong on 2021/4/3.
//

#include "media-func/listener.hpp"

void listenStream(const string &url, const string &app_name, const string &stream_id) {
    auto poller = EventPollerPool::Instance().getPoller();

    PlayerProxy::Ptr player(
            new PlayerProxy(
                    DEFAULT_VHOST,
                    "app",
                    "stream",
                    false,
                    false,
                    -1 ,
                    poller )
            );

    player->play(url.data());

    auto r = Recorder::startRecord(
            Recorder::type_mp4,
            DEFAULT_VHOST,
            app_name,
            stream_id,
            ""
            );
    if (!r) {
        ErrorL << app_name << stream_id << "录制错误";
    }

}

