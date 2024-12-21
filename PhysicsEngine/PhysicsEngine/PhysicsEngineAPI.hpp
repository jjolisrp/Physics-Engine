#ifndef PHYSICS_ENGINE_API_HPP
#define PHYSICS_ENGINE_API_HPP

#ifdef PHYSICS_ENGINE_EXPORTS
	#define PHYSICS_ENGINE_API __declspec(dllexport)
#else
	#define PHYSICS_ENGINE_API __declspec(dllimport)
#endif

#endif // PHYSICS_ENGINE_API_HPP