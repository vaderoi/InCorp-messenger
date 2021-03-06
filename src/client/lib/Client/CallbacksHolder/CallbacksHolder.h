#ifndef APPLICATION_CALLBACKSHOLDER_H
#define APPLICATION_CALLBACKSHOLDER_H

#include <map>
#include <memory>
#include <functional>

#include "Callback/BaseCallback.h"


// Holder for save callback functions
class CallbacksHolder {
public:
    
    // Add temporary callback 
    int addCallback(int command, const std::shared_ptr<BaseCallback>& callback) {
        auto callbackId = callbacks.count(command) + 1;
        callbacks.insert(std::pair<int, std::pair<int, const std::shared_ptr<BaseCallback>>>
                         (command, std::pair<int, const std::shared_ptr<BaseCallback>>(callbackId, callback)));
        return callbackId;
    }

	// Add system callback 
    int addCallback(int command, int numRequest, const std::shared_ptr<BaseCallback>& callback) {
        auto callbackId = numRequest;
        callbacks.insert(std::pair<int, std::pair<int, const std::shared_ptr<BaseCallback>>>
                                 (command, std::pair<int, const std::shared_ptr<BaseCallback>>(callbackId, callback)));
        return callbackId;
    }

    // Get callback by num command and num request
    std::shared_ptr<BaseCallback> getCallback(int command, int position) {
        auto iterator1 = callbacks.equal_range(command);

        for (; iterator1.first != iterator1.second; iterator1.first++) {
            auto iterator2 = iterator1.first;
            if (iterator2->second.first == position) {
                auto func = iterator2->second.second;
                if (command >= 0)
                    callbacks.erase(iterator2);
                return func;
            }
        }

        throw std::runtime_error("User callback function not found!");
    }

private:
    std::multimap<int, std::pair<int, std::shared_ptr<BaseCallback>>> callbacks;
};


#endif //APPLICATION_CALLBACKSHOLDER_H
