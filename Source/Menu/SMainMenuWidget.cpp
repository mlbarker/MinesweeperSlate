// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenuWidget.h"
#include "MenuPlayerController.h"
#include "MenuHUD.h"

#define LOCTEXT_NAMESPACE "MainMenu"

void SMainMenuWidget::Construct(const FArguments& InArgs)
{
    // caching the reference to OwningHUD
    OwningHUD = InArgs._OwningHUD;

    const FMargin ContentPadding = FMargin(500.f, 300.f);
    const FMargin ButtonPadding = FMargin(10.f);
    const FMargin TextBlockPadding = FMargin(20.f);

    const FText WidthText = LOCTEXT("Width", "Width:");
    const FText HeightText = LOCTEXT("Height", "Height:");

    const FText TitleText = LOCTEXT("GameTitle", "Minesweeper");
    const FText PlayText = LOCTEXT("PlayGame", "Play");
    const FText SettingsText = LOCTEXT("Settings", "Settings");
    const FText QuitText = LOCTEXT("QuitGame", "Quit Game");


    FSlateFontInfo DimensionTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
    DimensionTextStyle.Size = 60.f;

    FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
    ButtonTextStyle.Size = 40.f;

    FSlateFontInfo TitleTextStyle = ButtonTextStyle;
    TitleTextStyle.Size = 60.f;

    ChildSlot
        [
            // background
            SNew(SOverlay)
            + SOverlay::Slot()
            .HAlign(HAlign_Fill)
            .VAlign(VAlign_Fill)
            [
                SNew(SImage)
                .ColorAndOpacity(FColor::Black)
            ]

            + SOverlay::Slot()
            .HAlign(HAlign_Fill)
            .VAlign(VAlign_Top)
            [
                SNew(SHorizontalBox)

                // width
                + SHorizontalBox::Slot()
                [
                    SNew(STextBlock)
                    .Font(DimensionTextStyle)
                    .Text(WidthText)
                    .Justification(ETextJustify::Right)
                ]

                // width editable box
                + SHorizontalBox::Slot()
                [
                    SNew(SEditableTextBox)
                    .Justification(ETextJustify::Left)
                ]

                // height
                + SHorizontalBox::Slot()
                [
                    SNew(STextBlock)
                    .Font(DimensionTextStyle)
                    .Text(HeightText)
                    .Justification(ETextJustify::Right)
                ]

                // height editable box
                + SHorizontalBox::Slot()
                [
                    SNew(SEditableTextBox)
                    .Justification(ETextJustify::Left)
                ]
            ]

            + SOverlay::Slot()
            .HAlign(HAlign_Fill)
            .VAlign(VAlign_Fill)
            .Padding(ContentPadding)
            [
                SNew(SVerticalBox)
                + SVerticalBox::Slot()
                
            ]
        ];
}

FReply SMainMenuWidget::OnPlayClicked() const
{
    if (OwningHUD.IsValid())
    {
        OwningHUD->RemoveMenu();
    }

    return FReply::Handled();
}

FReply SMainMenuWidget::OnSettingsClicked() const
{
    return FReply::Handled();
}

FReply SMainMenuWidget::OnQuitClicked() const
{
    if (OwningHUD.IsValid())
    {
        if (APlayerController* PC = OwningHUD->PlayerOwner)
        {
            PC->ConsoleCommand("quit");
        }
    }

    return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
