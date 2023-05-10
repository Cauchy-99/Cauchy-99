#include "HowToUnique3DPoint.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

// TODO:在头文件中重载之后，编译会报错
std::ostream& operator<<(std::ostream& out, CATMathPoint& A) {
	out << "(" << A.GetX() << "," << A.GetY() << "," << A.GetZ() << ")";
	return out;
}

std::ostream& operator<<(std::ostream& out, CATMathPoint_var A) {
	out << "(" << A->GetX() << "," << A->GetY() << "," << A->GetZ() << ")";
	return out;
}


/**************************************************
* @ brief:     判断 CATMathPoint 大小
*              注：不可以直接用小于号对比两个值的大小作为返回依据，这样会产生歧义，导致sort崩溃
*              1.对于任意元素a，需满足 comp(a, a) == false
*              2.对于任意两个元素a和b，若 comp(a, b)==true 则要满足 comp(b, a)==false
*              3.对于任意三个元素a、b和c，若 comp(a, b)==true 且 comp(b, c)==true 则需要满足 comp(a, c)==true
* @ returns:   bool
* @ parameter: const CATMathPoint & lhs
* @ parameter: const CATMathPoint & rhs
***************************************************/
bool ComparePoint(CATMathPoint_var lhs, CATMathPoint_var rhs) {
  if (lhs->GetX() + 0.001 < rhs->GetX())
    return true;
  else if (abs(lhs->GetX() - rhs->GetX()) < 0.001) {
    if (lhs->GetY() + 0.001 < rhs->GetY())
      return true;
    else if (abs(lhs->GetY() - rhs->GetY()) < 0.001) {
      if (lhs->GetZ() + 0.001 < rhs->GetZ())
        return true;
    }
  }
  return false;
}

bool ComparePoint2(CATMathPoint_var lhs, CATMathPoint_var rhs) {
	if (lhs->GetX() < rhs->GetX()) {
		return true;
	}
	else if (lhs->GetX() == rhs->GetX() && lhs->GetY() < rhs->GetY()) {
		return true;
	}
	else if (lhs->GetX() == rhs->GetX() && lhs->GetY() == rhs->GetY() && lhs->GetZ() < rhs->GetZ()) {
		return true;
	}
	return false;
}

class Point3dCompare {
public:
  bool operator()(CATMathPoint_var lhs, CATMathPoint_var rhs) const {
    return ComparePoint(lhs, rhs);
  }
};

class uniquePoint3d {
public:
  bool operator()( CATMathPoint_var lhs, CATMathPoint_var rhs) const {
    return (lhs->GetX() == rhs->GetX() && lhs->GetY() == rhs->GetY() &&
            lhs->GetZ() == rhs->GetZ());
  }
};

HowToUnique3DPoint::HowToUnique3DPoint():
  m_iCountofPoint(10000),
  m_bRandomPoint(true)
{
	m_Points.reserve(m_iCountofPoint);
}

HowToUnique3DPoint::HowToUnique3DPoint(const int& iCount, bool bRandom):
	m_iCountofPoint(iCount),
	m_bRandomPoint(bRandom)
{
	m_Points.reserve(m_iCountofPoint);
}

HowToUnique3DPoint::~HowToUnique3DPoint() {
	if (m_Points.size())
	{

	}
}

void HowToUnique3DPoint::Run() {
	// 初始化数据量
	if (!m_Points.size()){ // 不管是否要随机生成，只要 m_Points 没有数据就尝试 push_back
		for (int i = 0; i < m_iCountofPoint; i++) {
			m_Points.push_back(CATMathPoint_var(new CATMathPoint()));
		}
	}

	// 有可能m_Points 没有数据
	if (m_Points.size()) {
		Calculate();
	}
	else {
		cout << "error: there is no point to calculate" << endl;
	}
	return;
}


bool HowToUnique3DPoint::Calculate()
{
	//int i = 1;
	//for (auto it = m_Points.begin(); it != m_Points.end(); it++) {
	//	cout << (*it) << "\t";
	//	if (i % 5 == 0) cout << endl;
	//	i++;
	//}

	// 对数据进行排序
	cout << "#after sort:***********************************************************" << endl;
	 //i = 1;
	Point3dCompare a;
	
	sort(m_Points.begin(), m_Points.end(), Point3dCompare());
	//for (auto it = m_Points.begin(); it != m_Points.end(); it++) {
	//	cout << (*it) << "\t";
	//	if (i % 5 == 0) cout << endl;
	//	i++;
	//}

	// 对数据去重处理
	cout << "#after unique:***********************************************************" << endl;
	//i = 1;

	// 
	m_Points.erase(unique(m_Points.begin(), m_Points.end(), uniquePoint3d()), m_Points.end());
	//for (auto it = m_Points.begin(); it != m_Points.end(); it++) {
	//	cout << (*it) << "\t";
	//	if (i % 5 == 0) cout << endl;
	//	i++;
	//}

	return true;
}


