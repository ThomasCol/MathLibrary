#ifndef __ORIENTEDBOX_H__
#define __ORIENTEDBOX_H__

#include "Box.h"
#include "Segment.h"
#include "Plane.h"


namespace Math::Geometry
{
	/**
	 * @brief QXorientedBox class
	 * 
	 */
	class QXorientedBox
	{
	private:
		#pragma region Attributes
		Box		m_box;
		QXvec3	m_i;
		QXvec3	m_j;
		QXvec3	m_k;
		#pragma endregion Attributes

	public:
		#pragma region Constructors/Destructor
		/**
		 * @brief Construct a new QXorientedBox object
		 * 
		 * @param box 
		 * @param i 
		 * @param j 
		 * @param k 
		 */
		QXorientedBox(const Box& box = Box(), const QXvec3& i = QXvec3(1, 0, 0),
				const QXvec3& j = QXvec3(1, 0, 0), const QXvec3& k = QXvec3(1, 0, 0)) noexcept;

		/**
		 * @brief Construct a new QXorientedBox object
		 * 
		 * @param box QXorientedBox to copy
		 * @param offsetExtention 
		 */
		QXorientedBox(const QXorientedBox& box, const QXfloat& offsetExtention = 0.f) noexcept;

		/**
		 * @brief Construct a new QXorientedBox object
		 * 
		 * @param box QXorientedBox to move
		 */
		QXorientedBox(QXorientedBox&& box) noexcept;

		/**
		 * @brief Destroy the QXorientedBox object
		 * 
		 */
		~QXorientedBox() = default;
		#pragma endregion Constructors/Destructor

		#pragma region Methods
		#pragma region Accessors

		/**
		 * @brief Get the Box object
		 * 
		 * @return Box 
		 */
		inline QXbox	GetBox() const {return m_box;}

		/**
		 * @brief Get the Position object
		 * 
		 * @return QXvec3 
		 */
		inline QXvec3	GetPosition() const {return m_box.GetPosition();}

		/**
		 * @brief Get the I of the referentiel
		 * 
		 * @return QXvec3 
		 */
		inline QXvec3	GetI() const {return m_i;}

		/**
		 * @brief Get the J of the referentiel
		 * 
		 * @return QXvec3 
		 */
		inline QXvec3	GetJ() const {return m_j;}

		/**
		 * @brief Get the K of the referentiel
		 * 
		 * @return QXvec3 
		 */
		inline QXvec3	GetK() const {return m_k;}

		/**
		 * @brief Get the X of the referentiel
		 * 
		 * @return QXvec3 
		 */
		inline QXfloat	GetX() const {return m_box.X();}

		/**
		 * @brief Get the Y of the referentiel
		 * 
		 * @return QXvec3 
		 */
		inline QXfloat	GetY() const {return m_box.Y();}

		/**
		 * @brief Get the Z of the referentiel
		 * 
		 * @return QXvec3 
		 */
		inline QXfloat	GetZ() const {return m_box.Z();}

		/**
		 * @brief Get the AABB of the oriented box
		 * 
		 * @return QXBox 
		 */
		QXbox			GetABB() const;

		/**
		 * @brief Get the Points object
		 * 
		 * @return QXvec3* 
		 */
		QXvec3*			GetPoints() const;

		/**
		 * @brief Get the Top Plane object
		 * 
		 * @return QXplane 
		 */
		QXplane			GetTopPlane() const;

		/**
		 * @brief Get the Bottom Plane object
		 * 
		 * @return QXplane 
		 */
		QXplane			GetBottomPlane() const;

		/**
		 * @brief Get the Front Plane object
		 * 
		 * @return QXplane 
		 */
		QXplane			GetFrontPlane() const;

		/**
		 * @brief Get the Back Plane object
		 * 
		 * @return QXplane 
		 */
		QXplane			GetBackPlane() const;

		/**
		 * @brief Get the Left Plane object
		 * 
		 * @return QXplane 
		 */
		QXplane			GetLeftPlane() const;

		/**
		 * @brief Get the Right Plane object
		 * 
		 * @return QXplane 
		 */
		QXplane			GetRightPlane() const;

		/**
		 * @brief Get the Number Plane Good Side object
		 * 
		 * @param point QXvec 
		 * @return QXint number of planes that are in the good side
		 */
		QXint			GetNumberPlaneGoodSide(const QXvec3& point) const;

		/**
		 * @brief Get the Nearest Segment object
		 * 
		 * @param point 
		 * @return QXsegment nearest segment in relation to the point and the oriented box
		 */
		QXsegment		GetNearestSegment(const QXvec3& point) const;

		/**
		 * @brief Get the Nearest Point object
		 * 
		 * @param point 
		 * @return QXvec3 nearest point in relation to the point and the oriented box
		 */
		QXvec3			GetNearestPoint(const QXvec3& point) const;

		/**
		 * @brief Get the Segments With This Point object
		 * 
		 * @param point 
		 * @return QXsegment* between the point and the oriented box
		 */
		QXsegment*		GetSegmentsWithThisPoint(const QXvec3& point) const;
		#pragma endregion Accessors

		#pragma region Operator

		/**
		 * @brief Operator = by copy
		 * 
		 * @param box to copy
		 * @return QXorientedBox& 
		 */
		QXorientedBox&	operator=(const QXorientedBox& box);
		#pragma endregion Operator
		#pragma endregion Methods
	};
}



#endif
