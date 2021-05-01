//
// Created by Azad_zhong on 2021/4/3.
//

#ifndef SHINO_PUSHER_HPP
#define SHINO_PUSHER_HPP

#include <csignal>
#include <iostream>
#include "Util/logger.h"
#include "Util/NoticeCenter.h"
#include "Poller/EventPoller.h"
#include "Player/PlayerProxy.h"
#include "Rtmp/RtmpPusher.h"
#include "Common/config.h"
#include "Pusher/MediaPusher.h"
#include "Record/MP4Reader.h"

using namespace std;
using namespace toolkit;
using namespace mediakit;

//声明函数
//推流失败或断开延迟2秒后重试推流
void rePushDelay(const EventPoller::Ptr &poller,
                 const string &schema,
                 const string &vhost,
                 const string &app,
                 const string &stream,
                 const string &filePath,
                 const string &url);

#endif //SHINO_PUSHER_HPP
