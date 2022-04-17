#include "Info.h"

Info& Info::getInstance() {
    static Info  instance;
    return instance;
}