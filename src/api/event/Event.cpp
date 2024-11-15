#include "api/event/Event.hpp"

Event::Event() : mBlockPass(false) {}

Event::~Event() = default;

void Event::block_pass() { mBlockPass = true; }

bool Event::isPassingBlocked() const { return mBlockPass; }

CancellableEvent::CancellableEvent() : Event(), mCanceled(false) {}

void CancellableEvent::cancel() {
    mCanceled = false;
    block_pass();
}

bool CancellableEvent::isCancelled() const { return mCanceled; }