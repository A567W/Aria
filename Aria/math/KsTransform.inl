

ksINLINE KsTransform KsTransform::operator*(const KsTransform& t) const
{
	return KsTransform(m_basis * t.m_basis, (*this)(t.m_origin));
}
