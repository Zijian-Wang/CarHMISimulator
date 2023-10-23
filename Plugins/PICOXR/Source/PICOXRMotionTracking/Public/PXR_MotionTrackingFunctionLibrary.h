// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

#include "PXR_MotionTrackingTypes.h"
#include "PXR_MotionTrackingFunctionLibrary.generated.h"

/// @file PXR_MotionTracking.h

/** @defgroup MotionTracking MotionTracking
 *  This is the MotionTracking group
 *  @{
 */


UCLASS()
class  PICOXRMOTIONTRACKING_API UPICOXRMotionTrackingFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/// <summary>
	/// Gets whether the current device supports face tracking.
	/// </summary>
	/// <param name="Supported">Indicates whether the device supports face tracking:
	/// * `true`: support
	/// * `false`: not support
	/// </param>
	/// <param name="supportedModes">Returns the specific face tracking modes supported by the device.</param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|FaceTracking")
		static bool GetFaceTrackingSupported(bool& Supported, TArray<EPXRFaceTrackingMode>& SupportedModes);

	/// <summary>
	/// Gets the state of face tracking.
	/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.
	/// </summary>
	/// <param name="isTracking">Returns a bool indicating whether face tracking is working:
	/// * `true`: face tracking is working
	/// * `false`: face tracking has been stopped
	/// </param>
	/// <param name="TrackingState">Returns the state of face tracking, including the face tracking mode and face tracking state code.
	/// </param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|FaceTracking")
		static bool GetFaceTrackingState(bool& IsTracking, FPXRFaceTrackingState& TrackingState);

	/// <summary>
	/// Starts face tracking.
	/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.
	/// </summary>
	/// <param name="StartInfo">Passes the information for starting face tracking.</param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|FaceTracking")
		static bool StartFaceTracking(const FPXRFaceTrackingStartInfo& StartInfo);

	/// <summary>
	/// Stops face tracking.
	/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.
	/// </summary>
	/// <param name="StopInfo">Passes the information for stopping face tracking.</param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|FaceTracking")
		static bool StopFaceTracking(const FPXRFaceTrackingStopInfo& StopInfo);

	/// <summary>
	/// Gets face tracking data.
	/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.
	/// </summary>
	/// <param name="GetInfo">Specifies the face tracking data you want.</param>
	/// <param name="OutFaceTrackingData">Returns the desired face tracking data.</param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|FaceTracking")
		static bool GetFaceTrackingData(const FPXRFaceTrackingDataGetInfo& GetInfo, FPXRFaceTrackingData& OutFaceTrackingData);

	/// <summary>
	/// Gets whether the current device supports eye tracking.
	/// </summary>
	/// <param name="Supported">
	/// Returns a bool indicating whether eye tracking is supported:
	/// * `true`: supported
	/// * `false`: not supported
	/// </param>
	/// <param name="supportedModes">
	/// Returns the eye tracking modes supported by the current device.
	/// </param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool GetEyeTrackingSupported(bool& Supported, TArray<EPXREyeTrackingMode>& SupportedModes);

	/// <summary>
	/// Gets the state of eye tracking.
	/// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="IsTracking">Returns a bool that indicates whether eye tracking is working:
	/// * `true`: eye tracking is working
	/// * `false`: eye tracking has been stopped
	/// </param>
	/// <param name="TrackingState">Returns the eye tracking state information, including the eye tracking mode and eye tracking state code.</param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool GetEyeTrackingState(bool& IsTracking, FPXREyeTrackingState& TrackingState);

	/// <summary>
	/// Starts eye tracking.
	/// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="StartInfo">Passes the information for starting eye tracking.
	/// </param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool StartEyeTracking(const FPXREyeTrackingStartInfo& StartInfo);

	/// <summary>
	/// Stops eye tracking.
	/// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="StopInfo">Passes the information for stopping eye tracking. Currently, you do not need to pass anything.</param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool StopEyeTracking(const FPXREyeTrackingStopInfo& StopInfo);

	/// <summary>Gets eye tracking data.
    /// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise. To call this API, you need to enable eye tracking first for your project.
	/// </summary>
	/// <param name="GetInfo">Specifies the eye tracking data you want.</param>
	/// <param name="OutEyeTrackingData">Returns the desired eye tracking data.
	/// The structure containing the following details:
    /// <ul>
    /// <li>`LeftEyePoseStatus`: Int, the current pose status of the left eye: `0` - data available; `1` - data not available</li>
    /// <li>`RightEyePoseStatus`: Int, the current pose status of the right eye: `0` - data available; `1` - data not available
	/// <li>`CombinedEyePoseStatus`: Int, the current combined pose status of the left and right eye: : 0 - data available; 1 - data not available</li>
	/// <li>`CombinedEyeGazePoint`: Vector, the current combined gaze point of the left and right eye</li>
	/// <li>`CombinedEyeGazeVector`: Vector, the current combined gaze direction of the left and right eye (from the midpoint between two eyes to the gaze point）</li>
	/// <li>`LeftEyeOpenness`: Float, the current openness of the left eye: `0.0` - eye closed; `1.0` - eye open</li>
	/// <li>`RightEyeOpenness`: Float, the current openness of the right eye: `0.0` - eye closed; `1.0` - eye open</li>
	/// <li>`LeftEyeOpenness`: Float, the current openness of the left eye: `0.0` - eye closed; `1.0` - eye open</li>
	/// <li>`LeftEyePositionGuide`: Vector, the position guide for the left eye</li>
	/// <li>`RightEyePositionGuide`: Vector, the position guide for the right eye</li>
    /// <li>`FoveatedGazeDirection`: Vector, the gazing ray direction (the center of FFR implemented)</li>
    /// </ul>
	/// </param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking", meta = (WorldToMetersScale = "100.0"))
		static bool GetEyeTrackingData(float WorldToMetersScale, const FPXREyeTrackingDataGetInfo& GetInfo, FPXREyeTrackingData& OutEyeTrackingData);

	/// <summary>
	/// Gets the openness of the left and right eyes.
	/// @note Supported by PICO 4 Enterprise.
	/// </summary>
	/// <param name="LeftEyeOpenness">The openness of the left eye, which is a float value ranges from `0.0` to `1.0`. `0.0` indicates completely closed, `1.0` indicates completely open.</param>
	/// <param name="RightEyeOpenness">The openness of the right eye, which is a float value ranges from `0.0` to `1.0`. `0.0` indicates completely closed, `1.0` indicates completely open.</param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool GetEyeOpenness(float& LeftEyeOpenness, float& RightEyeOpenness);

	/// <summary>
	/// Gets the information about the pupils of both eyes.
	/// @note Supported by PICO 4 Enterprise.
	/// </summary>
	/// <param name="EyePupilInfo">Returns the diameters and positions of both pupils.</param>
	/// <returns>Returns `0` for success and other values for failure.</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool GetEyePupilInfo(FPXREyePupilInfo& EyePupilInfo);
};
