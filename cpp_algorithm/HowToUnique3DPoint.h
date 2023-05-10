#pragma once
#include "HowTo.h"
#include <vector>
#include "CATMathPoint.h"
using std::vector;

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
  inline void InputPoints(vector<CATMathPoint_var>& iPoints) {
		m_Points = iPoints;
	}

private:
  int  m_iCountofPoint;    // 需要测试多少个点，默认值为10000
  bool m_bRandomPoint;    // 是否随机生成点，默认随机生成。
  vector<CATMathPoint_var> m_Points;
};
