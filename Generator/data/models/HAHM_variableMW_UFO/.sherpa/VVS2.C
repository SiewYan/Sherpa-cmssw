#include "METOOLS/Explicit/Lorentz_Calculator.H"
#include "METOOLS/Currents/C_Scalar.H"
#include "METOOLS/Currents/C_Spinor.H"
#include "METOOLS/Currents/C_Vector.H"
#include "METOOLS/Explicit/Vertex.H"
#include "MODEL/Main/Single_Vertex.H"
#include "ATOOLS/Org/Message.H"
#include "ATOOLS/Org/Exception.H"

typedef std::complex<double> complex;

namespace METOOLS {

  template <typename SType>
  class VVS2_Calculator: public Lorentz_Calculator {
  public:
    
    VVS2_Calculator(const Vertex_Key &key):
      Lorentz_Calculator(key) {}

    std::string Label() const { return "VVS2"; }

    CObject *Evaluate(const CObject_Vector &jj)
    {

// if outgoind UFO-index is 0
if (p_v->V()->id.back()==0){
const CVec4 <SType> & j1 = *(jj[0]->Get< CVec4 <SType> >());
const ATOOLS::Vec4D & p1 = p_v->J(0)->P();
const CScalar <SType> & j2 = *(jj[1]->Get< CScalar <SType> >());
const ATOOLS::Vec4D & p2 = p_v->J(1)->P();
ATOOLS::Vec4D p0 = -p1-p2;
CVec4<SType>* j0 = NULL;
j0 = CVec4<SType>::New();
(*j0)[0] = (((p1[0]) * (p0[0]) - ((p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()])))) * (j1[0]) - (((p1[0]) * (p0[ATOOLS::Spinor<SType>::R1()])) * (j1[ATOOLS::Spinor<SType>::R1()])) - (((p1[0]) * (p0[ATOOLS::Spinor<SType>::R2()])) * (j1[ATOOLS::Spinor<SType>::R2()])) - (((p1[0]) * (p0[ATOOLS::Spinor<SType>::R3()])) * (j1[ATOOLS::Spinor<SType>::R3()]))) * (j2[0]);
(*j0)[ATOOLS::Spinor<SType>::R1()] = (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[0])) * (j1[0]) - (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[ATOOLS::Spinor<SType>::R1()]) + (p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()]))) * (j1[ATOOLS::Spinor<SType>::R1()])) - (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[ATOOLS::Spinor<SType>::R2()])) * (j1[ATOOLS::Spinor<SType>::R2()])) - (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[ATOOLS::Spinor<SType>::R3()])) * (j1[ATOOLS::Spinor<SType>::R3()]))) * (j2[0]);
(*j0)[ATOOLS::Spinor<SType>::R2()] = (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[0])) * (j1[0]) - (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[ATOOLS::Spinor<SType>::R1()])) * (j1[ATOOLS::Spinor<SType>::R1()])) - (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[ATOOLS::Spinor<SType>::R2()]) + (p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()]))) * (j1[ATOOLS::Spinor<SType>::R2()])) - (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[ATOOLS::Spinor<SType>::R3()])) * (j1[ATOOLS::Spinor<SType>::R3()]))) * (j2[0]);
(*j0)[ATOOLS::Spinor<SType>::R3()] = (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[0])) * (j1[0]) - (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[ATOOLS::Spinor<SType>::R1()])) * (j1[ATOOLS::Spinor<SType>::R1()])) - (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[ATOOLS::Spinor<SType>::R2()])) * (j1[ATOOLS::Spinor<SType>::R2()])) - (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[ATOOLS::Spinor<SType>::R3()]) + (p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()]))) * (j1[ATOOLS::Spinor<SType>::R3()]))) * (j2[0]);
j0->SetS(j1.S()|j2.S());
return j0;

}

// if outgoind UFO-index is 1
if (p_v->V()->id.back()==1){
const CVec4 <SType> & j0 = *(jj[1]->Get< CVec4 <SType> >());
const ATOOLS::Vec4D & p0 = p_v->J(1)->P();
const CScalar <SType> & j2 = *(jj[0]->Get< CScalar <SType> >());
const ATOOLS::Vec4D & p2 = p_v->J(0)->P();
ATOOLS::Vec4D p1 = -p0-p2;
CVec4<SType>* j1 = NULL;
j1 = CVec4<SType>::New();
(*j1)[0] = (((p1[0]) * (p0[0]) - ((p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()])))) * (j0[0]) - (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[0])) * (j0[ATOOLS::Spinor<SType>::R1()])) - (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[0])) * (j0[ATOOLS::Spinor<SType>::R2()])) - (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[0])) * (j0[ATOOLS::Spinor<SType>::R3()]))) * (j2[0]);
(*j1)[ATOOLS::Spinor<SType>::R1()] = (((p1[0]) * (p0[ATOOLS::Spinor<SType>::R1()])) * (j0[0]) - (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[ATOOLS::Spinor<SType>::R1()]) + (p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()]))) * (j0[ATOOLS::Spinor<SType>::R1()])) - (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[ATOOLS::Spinor<SType>::R1()])) * (j0[ATOOLS::Spinor<SType>::R2()])) - (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[ATOOLS::Spinor<SType>::R1()])) * (j0[ATOOLS::Spinor<SType>::R3()]))) * (j2[0]);
(*j1)[ATOOLS::Spinor<SType>::R2()] = (((p1[0]) * (p0[ATOOLS::Spinor<SType>::R2()])) * (j0[0]) - (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[ATOOLS::Spinor<SType>::R2()])) * (j0[ATOOLS::Spinor<SType>::R1()])) - (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[ATOOLS::Spinor<SType>::R2()]) + (p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()]))) * (j0[ATOOLS::Spinor<SType>::R2()])) - (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[ATOOLS::Spinor<SType>::R2()])) * (j0[ATOOLS::Spinor<SType>::R3()]))) * (j2[0]);
(*j1)[ATOOLS::Spinor<SType>::R3()] = (((p1[0]) * (p0[ATOOLS::Spinor<SType>::R3()])) * (j0[0]) - (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[ATOOLS::Spinor<SType>::R3()])) * (j0[ATOOLS::Spinor<SType>::R1()])) - (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[ATOOLS::Spinor<SType>::R3()])) * (j0[ATOOLS::Spinor<SType>::R2()])) - (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[ATOOLS::Spinor<SType>::R3()]) + (p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()]))) * (j0[ATOOLS::Spinor<SType>::R3()]))) * (j2[0]);
j1->SetS(j0.S()|j2.S());
return j1;

}

// if outgoind UFO-index is 2
if (p_v->V()->id.back()==2){
const CVec4 <SType> & j0 = *(jj[0]->Get< CVec4 <SType> >());
const ATOOLS::Vec4D & p0 = p_v->J(0)->P();
const CVec4 <SType> & j1 = *(jj[1]->Get< CVec4 <SType> >());
const ATOOLS::Vec4D & p1 = p_v->J(1)->P();
ATOOLS::Vec4D p2 = -p0-p1;
CScalar<SType>* j2 = NULL;
j2 = CScalar<SType>::New((((p1[0]) * (p0[0]) - ((p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()])))) * (j0[0]) - (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[0])) * (j0[ATOOLS::Spinor<SType>::R1()])) - (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[0])) * (j0[ATOOLS::Spinor<SType>::R2()])) - (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[0])) * (j0[ATOOLS::Spinor<SType>::R3()]))) * (j1[0]) - ((((p1[0]) * (p0[ATOOLS::Spinor<SType>::R1()])) * (j0[0]) - (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[ATOOLS::Spinor<SType>::R1()]) + (p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()]))) * (j0[ATOOLS::Spinor<SType>::R1()])) - (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[ATOOLS::Spinor<SType>::R1()])) * (j0[ATOOLS::Spinor<SType>::R2()])) - (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[ATOOLS::Spinor<SType>::R1()])) * (j0[ATOOLS::Spinor<SType>::R3()]))) * (j1[ATOOLS::Spinor<SType>::R1()])) - ((((p1[0]) * (p0[ATOOLS::Spinor<SType>::R2()])) * (j0[0]) - (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[ATOOLS::Spinor<SType>::R2()])) * (j0[ATOOLS::Spinor<SType>::R1()])) - (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[ATOOLS::Spinor<SType>::R2()]) + (p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()]))) * (j0[ATOOLS::Spinor<SType>::R2()])) - (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[ATOOLS::Spinor<SType>::R2()])) * (j0[ATOOLS::Spinor<SType>::R3()]))) * (j1[ATOOLS::Spinor<SType>::R2()])) - ((((p1[0]) * (p0[ATOOLS::Spinor<SType>::R3()])) * (j0[0]) - (((p1[ATOOLS::Spinor<SType>::R1()]) * (p0[ATOOLS::Spinor<SType>::R3()])) * (j0[ATOOLS::Spinor<SType>::R1()])) - (((p1[ATOOLS::Spinor<SType>::R2()]) * (p0[ATOOLS::Spinor<SType>::R3()])) * (j0[ATOOLS::Spinor<SType>::R2()])) - (((p1[ATOOLS::Spinor<SType>::R3()]) * (p0[ATOOLS::Spinor<SType>::R3()]) + (p0[0]) * (p1[0]) - ((p0[ATOOLS::Spinor<SType>::R1()]) * (p1[ATOOLS::Spinor<SType>::R1()])) - ((p0[ATOOLS::Spinor<SType>::R2()]) * (p1[ATOOLS::Spinor<SType>::R2()])) - ((p0[ATOOLS::Spinor<SType>::R3()]) * (p1[ATOOLS::Spinor<SType>::R3()]))) * (j0[ATOOLS::Spinor<SType>::R3()]))) * (j1[ATOOLS::Spinor<SType>::R3()])));
j2->SetS(j0.S()|j1.S());
return j2;

}

    }

  };// end of class VVS2_Calculator

  template class VVS2_Calculator<double>;

}// end of namespace METOOLS

using namespace METOOLS;

DECLARE_GETTER(VVS2_Calculator<double>,"DVVS2",
	       Lorentz_Calculator,Vertex_Key);
Lorentz_Calculator *ATOOLS::Getter
<Lorentz_Calculator,Vertex_Key,VVS2_Calculator<double> >::
operator()(const Vertex_Key &key) const
{ return new VVS2_Calculator<double>(key); }

void ATOOLS::Getter<Lorentz_Calculator,Vertex_Key,
		    VVS2_Calculator<double> >::
PrintInfo(std::ostream &str,const size_t width) const
{ str<<"VVS2 vertex"; }
