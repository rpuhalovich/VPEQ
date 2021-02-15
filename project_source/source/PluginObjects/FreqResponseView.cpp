// created by Ryan Puhalovich - http://github.com/rpuhalovich

#include "FreqResponseView.hpp"

FreqResponseView::FreqResponseView(const VSTGUI::CRect &size, VSTGUI::IControlListener *listener, int32_t tag)
    : CView(size) {
        
}

FreqResponseView::~FreqResponseView() {}

void FreqResponseView::updateView() {

}

void FreqResponseView::pushDataValue(double data) {}

void FreqResponseView::draw(VSTGUI::CDrawContext *pContext) { 
    // --- below is example code ---------------
    // setup the background rectangle
    pContext->setLineWidth(1);
    pContext->setFillColor(VSTGUI::CColor(255, 255, 255, 255)); // white background
    pContext->setFrameColor(VSTGUI::CColor(0, 0, 0, 255)); // black borders
 
    // draw the rect filled (with white) and stroked (line around rectangle)
    pContext->drawRect(getViewSize(), VSTGUI::kDrawFilledAndStroked);
    
    // draw a line for the frequency selector
    pContext->drawLine(getViewSize().getTopCenter(), getViewSize().getBottomCenter());
    
    // draw a line for the frequency response
    pContext->drawLine(getViewSize().getLeftCenter(), getViewSize().getRightCenter());
 
    setDirty(false);
}

void FreqResponseView::setFreqs(Filter* filters) {
    for (int i = 0; i < NUM_FILTERS; i++) {
        filterFreqs[i] = filters[i].getParameters().fc;
    }
}

