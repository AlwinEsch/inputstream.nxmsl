/*
* Tree.cpp
*****************************************************************************
* Copyright (C) 2015-2016, liberty_developer
*
* Email: liberty.developer@xmail.net
*
* This source code and its use and distribution, is subject to the terms
* and conditions of the applicable license agreement.
*****************************************************************************/

#include <string>
#include <cstring>

#include "tree.h"
#include "../oscompat.h"
#include "../helpers.h"

using namespace manifest;

Tree::Tree()
  :download_speed_(0.0)
  , average_download_speed_(0.0f)
  , encryptionState_(ENCRYTIONSTATE_UNENCRYPTED)
  , current_period_(0)
{
}


Tree::~Tree()
{
}

/*----------------------------------------------------------------------
|   Tree
+---------------------------------------------------------------------*/

void Tree::Segment::SetRange(const char *range)
{
  const char *delim(strchr(range, '-'));
  if (delim)
  {
    range_begin_ = strtoull(range, 0, 10);
    range_end_ = strtoull(delim + 1, 0, 10);
  }
  else
    range_begin_ = range_end_ = 0;
}

bool Tree::open(const char *url)
{
  /*
  parser_ = XML_ParserCreate(NULL);
  if (!parser_)
    return false;
  XML_SetUserData(parser_, (void*)this);
  XML_SetElementHandler(parser_, start, end);
  XML_SetCharacterDataHandler(parser_, text);
  currentNode_ = 0;
  strXMLText_.clear();

  bool ret = download(url);
  
  XML_ParserFree(parser_);
  parser_ = 0;

  return ret;
  */
  return false;
}

bool Tree::write_data(void *buffer, size_t buffer_size)
{
  return false;
}

bool Tree::has_type(StreamType t)
{
  if (periods_.empty())
    return false;

  for (std::vector<AdaptationSet*>::const_iterator b(periods_[0]->adaptationSets_.begin()), e(periods_[0]->adaptationSets_.end()); b != e; ++b)
    if ((*b)->type_ == t)
      return true;
  return false;
}

uint32_t Tree::estimate_segcount(uint32_t duration, uint32_t timescale)
{
  double tmp(duration);
  duration /= timescale;
  return static_cast<uint32_t>((overallSeconds_ / duration)*1.01);
}

void Tree::set_download_speed(double speed)
{
  download_speed_ = speed;
  if (!average_download_speed_)
    average_download_speed_ = download_speed_;
  else
    average_download_speed_ = average_download_speed_*0.9 + download_speed_*0.1;
};
