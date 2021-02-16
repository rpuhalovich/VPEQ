// created by Ryan Puhalovich - http://github.com/rpuhalovich
// Custom view of the frequency response of the parametric eq.

#pragma once

#include "pch.hpp"

#include <pluginstructures.h>
#include <customviews.h>
#include <vstgui/vstgui.h>
#include "Filter.hpp"

struct FreqResponseViewMessage {
    FreqResponseViewMessage() {}
    FreqResponseViewMessage(const FreqResponseViewMessage& message) {
        fc = message.fc;
    }
    
    FreqResponseViewMessage& operator=(const FreqResponseViewMessage& message) {
        fc = message.fc;
        return *this;
    }
    
    double fc = 100.0f;
};

class FreqResponseView : public VSTGUI::CView, public ICustomView {
public:
    FreqResponseView(const VSTGUI::CRect& size, VSTGUI::IControlListener* listener, int32_t tag);
    ~FreqResponseView();

    // ICustomView
    virtual void updateView() override;
    virtual void pushDataValue(double data) override;
    
    // VSTGUI
    void draw(VSTGUI::CDrawContext *pContext) override;
    
    // member functions
    void setFreqs(Filter* filters);
private:
    double filterFreqs[NUM_FILTERS];
    
    // lock-free queue for incoming data, sized to DATA_QUEUE_LEN in length
    moodycamel::ReaderWriterQueue<double, VSTGUI::DATA_QUEUE_LEN>* dataQueue = nullptr;
};
