// created by Ryan Puhalovich - http://github.com/rpuhalovich
// Custom view of the frequency response of the parametric eq.

#pragma once

#include "pch.hpp"

#include <pluginstructures.h>
#include <customviews.h>
#include <vstgui/vstgui.h>

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
    void setFreqs();
private:
    double filterFreqs[NUM_FILTERS];
    
    // lock-free queue for incoming data, sized to DATA_QUEUE_LEN in length
    moodycamel::ReaderWriterQueue<double, VSTGUI::DATA_QUEUE_LEN>* dataQueue = nullptr;
};
