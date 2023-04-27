#pragma once
#include "HowTo.h"
#include <vector>
using std::vector;

class CATMathPoint;
class HowToUnique3DPoint : public HowTo {
public:
  HowToUnique3DPoint();
  HowToUnique3DPoint(const int& iCount, bool bRandom);
  ~HowToUnique3DPoint();

  void Run() override;

  bool Calculate() override;

public:
  inline void SetCountOfPoint(const int iCount) {
    m_iCountofPoint = iCount;
  };
	inline void SetRandomPoint(bool bRandom) {
    m_bRandomPoint = bRandom;
	};
  inline void InputPoints(vector<CATMathPoint*>& iPoints) {
		m_Points = iPoints;
	}

private:
  int  m_iCountofPoint;    // ��Ҫ���Զ��ٸ��㣬Ĭ��ֵΪ10000
  bool m_bRandomPoint;    // �Ƿ�������ɵ㣬Ĭ���������
  vector<CATMathPoint*> m_Points;
};
