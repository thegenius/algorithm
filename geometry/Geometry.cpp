/***************************************************
*  作者：汪蔚                                      *
*  更新：2014-07-17                                *
****************************************************/
#include "Geometry.h"

// 叉乘
float cross(Vec2 a, Vec2 b) {
	return  a.x*b.y - b.x*a.y;
}
// 点乘
float dot(Vec2 a, Vec2 b) {
	return a.x*b.x + a.y*b.y;
}
// 两点之间距离
float getDistance(Vec2 p1, Vec2 p2) {
	return sqrtf((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

// 给出定点，和一个圆，计算过定点的切线的切点坐标
/*******************************************************
*               通过向量旋转来实现                     *
********************************************************/
bool getTangentPoint(Vec2 point,                    //定点
					 Vec2 center, float radius,     //圆的中心和半径
					 Vec2& tangentPoint1, Vec2& tangentPoint2) {

	// 计算一个顶点指向圆心的向量
	Vec2 pointTo(center.x-point.x, center.y-point.y);

	//计算定点与圆心的距离
	float distance = sqrtf(pointTo.x*pointTo.x + pointTo.y*pointTo.y);
	if (fabs(distance-radius) < 1E-6) {
		return false;
	}

	// 计算顶点圆心连线与切线的夹角的sin, cos
	float sinA = radius/distance;
	float cosA = sqrtf(1.0 - sinA*sinA);
	
	// 旋转向量
	// cosA  -sinA 
	// sinA  cosA
	Vec2 tangentVec1 = Vec2(cosA*pointTo.x + (-sinA)*pointTo.y, 
		                    sinA*pointTo.x +    cosA*pointTo.y);
	// cosA   sinA 
	// -sinA  cosA
	Vec2 tangentVec2 = Vec2(cosA   *pointTo.x + sinA*pointTo.y, 
		                    (-sinA)*pointTo.x + cosA*pointTo.y);

	// 向量长度变换到切线长度
	tangentVec1.x *= cosA;
	tangentVec1.y *= cosA;
	tangentVec2.x *= cosA;
	tangentVec2.y *= cosA;

	// 生成最后的切点
	tangentPoint1 = Vec2(point.x+tangentVec1.x, point.y+tangentVec1.y);
	tangentPoint2 = Vec2(point.x+tangentVec2.x, point.y+tangentVec2.y);
	return true;
}

// 计算点到直线的距离
float getDistanceToLine(Vec2 pointC, Vec2 linePointA, Vec2 linePointB) {
	Vec2 ab = Vec2(linePointB.x - linePointA.x,
		           linePointB.y - linePointA.y);
	Vec2 ac = Vec2(pointC.x - linePointA.x,
				   pointC.y - linePointA.y);
	float absCross = fabs(cross(ab, ac));
	float ret =  absCross/getDistance(linePointA, linePointB);
	return ret;
}


// 计算点到线段的距离
float getDistanceToSegment(Vec2 pointC, Vec2 linePointA, Vec2 linePointB) {
	Vec2 ab = Vec2(linePointB.x - linePointA.x,
		           linePointB.y - linePointA.y);
	Vec2 ac = Vec2(pointC.x - linePointA.x,
				   pointC.y - linePointA.y);
	Vec2 bc = Vec2(pointC.x - linePointB.x,
				   pointC.y - linePointB.y);
	if (dot(ac, bc) < 1E-6) { 
		//小心精度控制，注意C在AB的延长线上的情况
		//点的垂足在线段上
		float absCross = fabs(cross(ab, ac));
		return absCross/getDistance(linePointA, linePointB);
	} else {
		//点的垂足在线段外
		float dis1 = getDistance(pointC, linePointA);
		float dis2 = getDistance(pointC, linePointB);
		return dis1<dis2 ? dis1:dis2;
	}
}

// 判断点是否在矩形中
// rectPoint1为左下角顶点 rectPoint2为右上角顶点
bool isRectContainPoint(Vec2 rectPoint1, Vec2 rectPoint2, Vec2 point) {
	if (point.x >= rectPoint1.x && 
		point.x <= rectPoint2.x &&
		point.y >= rectPoint1.y &&
		point.y <= rectPoint2.y) {
		return true;
	}
	return false;
}

// 判定矩形和圆是有重叠
bool isRectCircleOverlap(Vec2 rectPoint1, Vec2 rectPoint2, Vec2 center, float radius) {
	if (isRectContainPoint(rectPoint1, rectPoint2, center)) {
		return true;
	}
	//生成左上角顶点 和 右下角顶点  
	Vec2 rectPoint3 = Vec2(rectPoint1.x, rectPoint2.y);
	Vec2 rectPoint4 = Vec2(rectPoint2.x, rectPoint1.y);

	//   四个顶点的方位
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