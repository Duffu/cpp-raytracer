#pragma once
#include "core.h"
#include "hittable.h"

class sphere : public hittable {
public:
    sphere(const point3& center, double radius) : center(center), radius(std::fmax(0.0, radius)) {}
    bool hit(const ray& r, interval ray_t, hit_record& rec) const {
        
        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto half_b = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius * radius;
        auto discriminant = half_b * half_b - a * c;

        if (discriminant < 0) {
            return false;
        }

        auto sqrt_discriminant = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (half_b - sqrt_discriminant) / a;
        if (!ray_t.surrounds(root)) {
            root = (half_b + sqrt_discriminant) / a;
            if (!ray_t.surrounds(root)) {
                return false;
            }
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    }

private:
    point3 center;
    double radius;
};
