// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class SMainMenuWidget : public SCompoundWidget
{
public:

	// passing the MenuHUD class into the widget
	SLATE_BEGIN_ARGS(SMainMenuWidget) {}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)
	SLATE_END_ARGS()

	/** every widget needs a construction function */
	void Construct(const FArguments& InArgs);

	FReply OnPlayClicked() const;
	FReply OnSettingsClicked() const;
	FReply OnQuitClicked() const;

	/** the HUD that created this widget */
	TWeakObjectPtr<class AMenuHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; }
};
