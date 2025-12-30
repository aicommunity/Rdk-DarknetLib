#ifndef RDK_TDarknetUBitmapClassifierH
#define RDK_TDarknetUBitmapClassifierH

//#include "TPythonIntegrationInclude.h"
//#include "TPythonIntegrationUtil.h"
#include "../ThirdParty/darknet/include/darknet_utils.h"
#include "../../../Rdk/Deploy/Include/rdk.h"

namespace RDK {

class TDarknetUBitmapClassifier: public RDK::UNet
{
public: // 
///  
/// UProperty<UBitmap,TDarknetUBitmapClassifier, ptPubParameter> InputImage;

//     
///   ()  
UProperty<std::vector<UBitmap>, TDarknetUBitmapClassifier, ptPubInput> InputImages;

///  ,   ,    
/// ubmRGB24=3 -  
/// umbY8=400 - - 
UProperty<int,TDarknetUBitmapClassifier, ptPubParameter> ImageColorModel;

///    (    
UProperty<int,TDarknetUBitmapClassifier, ptPubParameter> NumClasses;
///  ,      (probability)
UProperty<float,TDarknetUBitmapClassifier, ptPubParameter> ProbabilityThreshold;
///  ,      (objectness)
UProperty<float,TDarknetUBitmapClassifier, ptPubParameter> ObjectnessThreshold;

///     
UProperty<std::vector<int>,TDarknetUBitmapClassifier, ptPubOutput> OutputClasses;

///  .     ,       
///   -  
UProperty<MDMatrix<double>, TDarknetUBitmapClassifier> OutputConfidences;

///    
UProperty<std::string,TDarknetUBitmapClassifier, ptPubParameter> ConfigPath;
///    
UProperty<std::string,TDarknetUBitmapClassifier, ptPubParameter> WeightsPath;

protected: //  

UGraphics Graph;
UBitmap Canvas;

bool Initialized;

network *Network;
//layer* TopLayer;

public: // 
// --------------------------
//   
// --------------------------
TDarknetUBitmapClassifier(void);
virtual ~TDarknetUBitmapClassifier(void);
// --------------------------

// --------------------------
//    
// --------------------------
//         
virtual TDarknetUBitmapClassifier* New(void);
// --------------------------

// --------------------------
//    
// --------------------------
protected:
bool Initialize(void);

virtual void AInit(void);
virtual void AUnInit(void);

//        
virtual bool ADefault(void);

//     
//   
//    Reset()   Ready  true
//    
virtual bool ABuild(void);

//      
virtual bool AReset(void);

//    
virtual bool ACalculate(void);
// --------------------------
image UBitmapToImage(const UBitmap& ub);
};


}

#endif



