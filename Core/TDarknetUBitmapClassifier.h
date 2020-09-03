#ifndef RDK_TDarknetUBitmapClassifierH
#define RDK_TDarknetUBitmapClassifierH

//#include "TPythonIntegrationInclude.h"
//#include "TPythonIntegrationUtil.h"

#include "../../Rdk-CRLib/Core/UClassifierBase.h"
#include "TDarknetComponent.h"

#define CLASS_UNDEFINED -2
#define CLASS_LOWQUAL -3

namespace RDK {

class TDarknetUBitmapClassifier: public UClassifierBase, public TDarknetComponent
{
public: // ��������

protected: // ���������� ���������




public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
TDarknetUBitmapClassifier(void);
virtual ~TDarknetUBitmapClassifier(void);
// --------------------------

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
virtual TDarknetUBitmapClassifier* New(void);
// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
protected:

// �������������� �������� �� ��������� � ����� �������� �����
virtual bool ADNDefault(void);

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
virtual bool ADNBuild(void);

// ����� �������� ����� ��� ������ ��������
virtual bool ADNReset(void);


// --------------------------

/// ������������ ���� �����������
virtual bool ClassifyBitmap(UBitmap &bmp, MDVector<double> &output_confidences, double conf_thresh, int &class_id, bool &is_classified);

};


}

#endif



