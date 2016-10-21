/**
 *  This source file implements the FuzzyControllerNode class, which is also a
 *  Node class via enhancement.
 *
 *  Version: 1.0.0
 *  Created on: 21/10/2016
 *  Modified on: 21/10/2016
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Professores de ECA419 (eca419.unifei@gmail.com)
 */

#include "aula6/FuzzyControllerNode.h"

namespace aula6
{

FuzzyControllerNode::FuzzyControllerNode(ros::NodeHandle *nh)
  : Node(nh, 30),
    counter_(0)
{
  engine_ = new fl::Engine("simple-dimmer");

  ambient_ = new fl::InputVariable;
  ambient_->setName("Ambient");
  ambient_->setRange(0.000, 1.000);
  ambient_->addTerm(new fl::Triangle("DARK", 0.000, 0.500));
  ambient_->addTerm(new fl::Triangle("MEDIUM", 0.250, 0.750));
  ambient_->addTerm(new fl::Triangle("BRIGHT", 0.500, 1.000));
  engine_->addInputVariable(ambient_);

  power_ = new fl::OutputVariable;
  power_->setName("Power");
  power_->setRange(0.000, 2.000);
  power_->setDefaultValue(fl::nan);
  power_->addTerm(new fl::Triangle("LOW", 0.000, 1.000));
  power_->addTerm(new fl::Triangle("MEDIUM", 0.500, 1.500));
  power_->addTerm(new fl::Triangle("HIGH", 1.000, 2.000));
  engine_->addOutputVariable(power_);

  rule_block_ = new fl::RuleBlock;
  rule_block_->addRule(fl::Rule::parse("if Ambient is DARK then Power is HIGH", engine_));
  rule_block_->addRule(fl::Rule::parse("if Ambient is MEDIUM then Power is MEDIUM", engine_));
  rule_block_->addRule(fl::Rule::parse("if Ambient is BRIGHT then Power is LOW", engine_));
  engine_->addRuleBlock(rule_block_);

  engine_->configure("", "", "Minimum", "Maximum", "Centroid");

  std::string status;
  if (!engine_->isReady(&status))
  {
    throw fl::Exception("Engine not ready. The following errors were encountered: " + status, FL_AT);
  }
}

FuzzyControllerNode::~FuzzyControllerNode()
{}

void FuzzyControllerNode::controlLoop()
{
  double light(ambient_->getMinimum() + counter_++ * (ambient_->range() / 50));
  ambient_->setInputValue(light);
  engine_->process();
  double output(power_->getOutputValue());
  ROS_INFO("Ambient.input = %f -> Power.output = %f", light, output);
  if (light > 1)
  {
    counter_ = 0;
  }
}

}
