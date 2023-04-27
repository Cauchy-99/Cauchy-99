#include "HowToUnique3DPoint.h"
#include "CATMathPoint.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;


/**************************************************
* @ brief:     �ж� CATMathPoint ��С
*              ע��������ֱ����С�ںŶԱ�����ֵ�Ĵ�С��Ϊ�������ݣ�������������壬����sort����
*              1.��������Ԫ��a�������� comp(a, a) == false
*              2.������������Ԫ��a��b���� comp(a, b)==true ��Ҫ���� comp(b, a)==false
*              3.������������Ԫ��a��b��c���� comp(a, b)==true �� comp(b, c)==true ����Ҫ���� comp(a, c)==true
* @ returns:   bool
* @ parameter: const CATMathPoint & lhs
* @ parameter: const CATMathPoint & rhs
***************************************************/
bool ComparePoint(const CATMathPoint &lhs, const CATMathPoint &rhs) {
  if (lhs.GetX() + 0.001 < rhs.GetX())
    return true;
  else if (abs(lhs.GetX() - rhs.GetX()) < 0.001) {
    if (lhs.GetY() + 0.001 < rhs.GetY())
      return true;
    else if (abs(lhs.GetY() - rhs.GetY()) < 0.001) {
      if (lhs.GetZ() + 0.001 < rhs.GetZ())
        return true;
    }
  }
  return false;
}

class Point3dCompare {
public:
  bool operator()(const CATMathPoint &lhs, const CATMathPoint &rhs) const {
    return ComparePoint(lhs, rhs);
  }
};

class uniquePoint3d {
public:
  bool operator()(const CATMathPoint &lhs, const CATMathPoint &rhs) const {
    return (lhs.GetX() == rhs.GetX() && lhs.GetY() == rhs.GetY() &&
            lhs.GetZ() == rhs.GetZ());
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
	// ��ʼ��������
	if (!m_Points.size()){ // �����Ƿ�Ҫ������ɣ�ֻҪ m_Points û�����ݾͳ��� push_back
		for (int i = 0; i < m_iCountofPoint; i++) {
			m_Points.push_back(new CATMathPoint());
		}
	}

	// �п���m_Points û������
	if (m_Points.size()) {
		Run();
	}
	else {
		cout << "error: there is no point to calculate" << endl;
	}
	return;
}


bool HowToUnique3DPoint::Calculate()
{
	// �����ݽ�������
	cout << "#after sort:***********************************************************" << endl;
	int i = 1;
	sort(m_Points.begin(), m_Points.end(), Point3dCompare());
	for (auto it = m_Points.begin(); it != m_Points.end(); it++) {
		cout << *it << "\t";
		if (i % 5 == 0) cout << endl;
		i++;
	}

	// ������ȥ�ش���
	cout << "#after unique:***********************************************************" << endl;
	i = 1;
	m_Points.erase(unique(m_Points.begin(), m_Points.end(), uniquePoint3d()), m_Points.end());
	for (auto it = m_Points.begin(); it != m_Points.end(); it++) {
		cout << *it << "\t";
		if (i % 5 == 0) cout << endl;
		i++;
	}

	return true;
}


