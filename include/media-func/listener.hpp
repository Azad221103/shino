//
// Created by Azad_zhong on 2021/4/3.
//

#ifndef SHINO_LISTENER_HPP
#define SHINO_LISTENER_HPP

#include <string>
#include "Poller/EventPoller.h"
#include "Player/PlayerProxy.h"
#include "Rtmp/RtmpPusher.h"
#include "Common/config.h"
#include "Pusher/MediaPusher.h"
#include "Record/Recorder.h"

using namespace std;
using namespace toolkit;
using namespace mediakit;

void listenStream(const string &url);

#endif //SHINO_LISTENER_HPP
