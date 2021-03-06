#pragma once

#include <vector>
#include <string>

#include "anim/bone_pose.h"
#include "anim/geoset_anim.h"

struct GeosetAnim;
struct BonePoseNode;

enum class InterpolationMode
{
	DontInterp = 0,
	Linear = 1
};

// This struct contains all the information relevant to animation. 
// Every animation update, this data must be traversed and the final transforms of each bone worked out for every object with a given animation.
struct Animation
{
	// Animation name
	std::string name;

	// Duration of animation in seconds
	float duration;

	// Number of frames in this animation
	unsigned int frame_count;

	// These contain the actual translation, rotation, and scaling information for each node in the animation hierarchy over time
	BonePoseNode* root_pose_node;
	std::vector<BonePoseNode> pose_nodes;

	// Geoset anims
	std::vector<GeosetAnim> geoset_anims;
};
