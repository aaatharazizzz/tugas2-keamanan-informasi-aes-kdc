#pragma once

enum class KDCScenario : int {
    RequestToKDC,
    KDCResponse,
    Forward,
    Handshake1,
    Handshake2
};