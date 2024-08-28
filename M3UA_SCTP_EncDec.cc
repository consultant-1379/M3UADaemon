///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Copyright Test Competence Center (TCC) ETH 2007                           //
//                                                                           //
// The copyright to the computer  program(s) herein  is the property of TCC. //
// The program(s) may be used and/or copied only with the written permission //
// of TCC or in accordance with  the terms and conditions  stipulated in the //
// agreement/contract under which the program(s) has been supplied.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
//
//  File:               M3UA_SCTP_EncDec.cc
//  Rev:                R4A01
//  Prodnr:             CNL 113 487
//  Updated:            2007-07-16
//  Contact:            http://ttcn.ericsson.se
//  Reference:          
///////////////////////////////////////////////////////////////////////////////


#include "M3UA_SCTP_Daemon.hh"
using namespace M3UA__SCTP__Types;

namespace M3UA__SCTP__Daemon {

//////////////////////////////////
// Encoding function for PDU_M3UA
//////////////////////////////////
OCTETSTRING enc__PDU__M3UA(const PDU__M3UA&
pl__PDU__M3UA)
{
  if (TTCN_Logger::log_this_event(TTCN_DEBUG))
  {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("M3UA EncDec: Encoding PDU_M3UA: ");
    pl__PDU__M3UA.log();
    TTCN_Logger::end_event();
  }
    
  TTCN_Buffer buf;
  pl__PDU__M3UA.encode(PDU__M3UA_descr_, buf, TTCN_EncDec::CT_RAW);
  OCTETSTRING ret_val(buf.get_len(), buf.get_data());

  if (TTCN_Logger::log_this_event(TTCN_DEBUG))
  {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("M3UA EncDec: PDU_M3UA encoded into: ");
    ret_val.log();
    TTCN_Logger::end_event();
  }

  return ret_val;
}

//////////////////////////////////
// Decoding function for PDU_M3UA
//////////////////////////////////
PDU__M3UA dec__PDU__M3UA(const OCTETSTRING& pl__octetstring)
{
  if (TTCN_Logger::log_this_event(TTCN_DEBUG))
  {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("M3UA EncDec: Decoding into PDU_M3UA: ");
    pl__octetstring.log();
    TTCN_Logger::end_event();
  }
    
  TTCN_Buffer buf;
  PDU__M3UA pdu;
  buf.put_os(pl__octetstring);
  pdu.decode(PDU__M3UA_descr_, buf, TTCN_EncDec::CT_RAW);

  if (TTCN_Logger::log_this_event(TTCN_DEBUG))
  {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("M3UA EncDec: Decoded PDU_M3UA: ");
    pdu.log();
    TTCN_Logger::end_event();
  }

  return pdu;
}

}//namespace 

