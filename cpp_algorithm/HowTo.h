#pragma once
class HowTo {
public:
  HowTo();
  ~HowTo();

  virtual void Run() = 0;

  virtual bool Calculate() = 0;

};
