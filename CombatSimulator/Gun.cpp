#include "Gun.h"

Gun::Gun(WeaponData* data_in)
	:
	Weapon(data_in),
	mReloadTimer(data_in->reloadTime)
{
	mBulletsLeft = data_in->maxMagazineSize;
}

void Gun::Update(const float dt_in)
{
	mCooldownTimer.Update(dt_in);

	if (!HasBullets())
	{
		mReloadTimer.Update(dt_in);

		if (mReloadTimer.limitReached())
		{
			Reload();
			std::cout << mData->ownerName << " reloaded his " << mData->name << ".\n" << std::endl;
		}
	}
}

bool Gun::Attack(const char* targetName_in, const char* ownerName_in)
{
	if (mCooldownTimer.limitReached() && HasBullets())
	{
		std::cout << ownerName_in << " used his " << mData->name << " and shot " << targetName_in << "." << std::endl;
		--mBulletsLeft;
		return true;
	}
	return false;
}

void Gun::Reload()
{
	mBulletsLeft = mData->maxMagazineSize;
}

bool Gun::HasBullets() const
{
	return mBulletsLeft > 0;
}

void Gun::Reset()
{
	mReloadTimer.Reset();
	mCooldownTimer.Reset();
}
