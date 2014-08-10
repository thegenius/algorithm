/***************************************************
*  ���ߣ���ε                                      *
*  ���£�2014-07-17                                *
****************************************************/
#include "Geometry.h"

// ���
float cross(Vec2 a, Vec2 b) {
	return  a.x*b.y - b.x*a.y;
}
// ���
float dot(Vec2 a, Vec2 b) {
	return a.x*b.x + a.y*b.y;
}
// ����֮�����
float getDistance(Vec2 p1, Vec2 p2) {
	return sqrtf((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

// �������㣬��һ��Բ���������������ߵ��е�����
/*******************************************************
*               ͨ��������ת��ʵ��                     *
********************************************************/
bool getTangentPoint(Vec2 point,                    //����
					 Vec2 center, float radius,     //Բ�����ĺͰ뾶
					 Vec2& tangentPoint1, Vec2& tangentPoint2) {

	// ����һ������ָ��Բ�ĵ�����
	Vec2 pointTo(center.x-point.x, center.y-point.y);

	//���㶨����Բ�ĵľ���
	float distance = sqrtf(pointTo.x*pointTo.x + pointTo.y*pointTo.y);
	if (fabs(distance-radius) < 1E-6) {
		return false;
	}

	// ���㶥��Բ�����������ߵļнǵ�sin, cos
	float sinA = radius/distance;
	float cosA = sqrtf(1.0 - sinA*sinA);
	
	// ��ת����
	// cosA  -sinA 
	// sinA  cosA
	Vec2 tangentVec1 = Vec2(cosA*pointTo.x + (-sinA)*pointTo.y, 
		                    sinA*pointTo.x +    cosA*pointTo.y);
	// cosA   sinA 
	// -sinA  cosA
	Vec2 tangentVec2 = Vec2(cosA   *pointTo.x + sinA*pointTo.y, 
		                    (-sinA)*pointTo.x + cosA*pointTo.y);

	// �������ȱ任�����߳���
	tangentVec1.x *= cosA;
	tangentVec1.y *= cosA;
	tangentVec2.x *= cosA;
	tangentVec2.y *= cosA;

	// ���������е�
	tangentPoint1 = Vec2(point.x+tangentVec1.x, point.y+tangentVec1.y);
	tangentPoint2 = Vec2(point.x+tangentVec2.x, point.y+tangentVec2.y);
	return true;
}

// ����㵽ֱ�ߵľ���
float getDistanceToLine(Vec2 pointC, Vec2 linePointA, Vec2 linePointB) {
	Vec2 ab = Vec2(linePointB.x - linePointA.x,
		           linePointB.y - linePointA.y);
	Vec2 ac = Vec2(pointC.x - linePointA.x,
				   pointC.y - linePointA.y);
	float absCross = fabs(cross(ab, ac));
	float ret =  absCross/getDistance(linePointA, linePointB);
	return ret;
}


// ����㵽�߶εľ���
float getDistanceToSegment(Vec2 pointC, Vec2 linePointA, Vec2 linePointB) {
	Vec2 ab = Vec2(linePointB.x - linePointA.x,
		           linePointB.y - linePointA.y);
	Vec2 ac = Vec2(pointC.x - linePointA.x,
				   pointC.y - linePointA.y);
	Vec2 bc = Vec2(pointC.x - linePointB.x,
				   pointC.y - linePointB.y);
	if (dot(ac, bc) < 1E-6) { 
		//С�ľ��ȿ��ƣ�ע��C��AB���ӳ����ϵ����
		//��Ĵ������߶���
		float absCross = fabs(cross(ab, ac));
		return absCross/getDistance(linePointA, linePointB);
	} else {
		//��Ĵ������߶���
		float dis1 = getDistance(pointC, linePointA);
		float dis2 = getDistance(pointC, linePointB);
		return dis1<dis2 ? dis1:dis2;
	}
}

// �жϵ��Ƿ��ھ�����
// rectPoint1Ϊ���½Ƕ��� rectPoint2Ϊ���ϽǶ���
bool isRectContainPoint(Vec2 rectPoint1, Vec2 rectPoint2, Vec2 point) {
	if (point.x >= rectPoint1.x && 
		point.x <= rectPoint2.x &&
		point.y >= rectPoint1.y &&
		point.y <= rectPoint2.y) {
		return true;
	}
	return false;
}

// �ж����κ�Բ�����ص�
bool isRectCircleOverlap(Vec2 rectPoint1, Vec2 rectPoint2, Vec2 center, float radius) {
	if (isRectContainPoint(rectPoint1, rectPoint2, center)) {
		return true;
	}
	//�������ϽǶ��� �� ���½Ƕ���  
	Vec2 rectPoint3 = Vec2(rectPoint1.x, rectPoint2.y);
	Vec2 rectPoint4 = Vec2(rectPoint2.x, rectPoint1.y);

	//   �ĸ�����ķ�λ
	//   3  2
	//   1  4

	float distance1 = getDistanceToSegment(center, rectPoint1, rectPoint3);
	if (distance1 < radius) {
		return true;
	}

	float distance2 = getDistanceToSegment(center, rectPoint3, rectPoint2);
	if (distance2 < radius) {
		return true;
	}

	float distance3 = getDistanceToSegment(center, rectPoint2, rectPoint4);
	if (distance3 < radius) {
		return true;
	}

	float distance4 = getDistanceToSegment(center, rectPoint4, rectPoint1);
	if (distance4 < radius) {
		return true;
	}

	return false;
}