/***************************************************
*  ���ߣ���ε                                      *
*  ���£�2014-07-17                                *
****************************************************/
#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__
#include <math.h>
#include <cocos2d.h>
USING_NS_CC;

// ���
float cross(Vec2 a, Vec2 b);

// ���
float dot(Vec2 a, Vec2 b);

// ����֮�����
float getDistance(Vec2 p1, Vec2 p2);

// ���� ���� �� һ��Բ ���������������ߵ��е�����
bool getTangentPoint(Vec2 point,                  
					 Vec2 center, float radius,     
					 Vec2& tangentPoint1, Vec2& tangentPoint2);

// ����㵽ֱ�ߵľ���
float getDistanceToLine(Vec2 pointC, Vec2 linePointA, Vec2 linePointB);

// ����㵽�߶εľ���
float getDistanceToSegment(Vec2 pointC, Vec2 linePointA, Vec2 linePointB);

// �жϵ��Ƿ��ھ�����
// rectPoint1Ϊ���½Ƕ��� rectPoint2Ϊ���ϽǶ���
bool isRectContainPoint(Vec2 rectPoint1, Vec2 rectPoint2, Vec2 point);

// �ж����κ�Բ�����ص�
// rectPoint1Ϊ���½Ƕ��� rectPoint2Ϊ���ϽǶ���
bool isRectCircleOverlap(Vec2 rectPoint1, Vec2 rectPoint2, Vec2 center, float radius);


#endif